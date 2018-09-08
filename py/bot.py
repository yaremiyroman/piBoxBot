# -*- coding: utf-8 -*-
import glob
import os
# import psutil
import platform
import sys
import config
import time
import math
import io
import telebot
import RPi.GPIO as GPIO
import Adafruit_DHT
from functools import wraps

############################################################################
#########################################################################
####################### INIT ###############################################
############################################################################
############################################################################

bot = telebot.TeleBot(config.token)
# It is possible that you have more than one
# script/circuit on the GPIO of your Raspberry Pi.
# As a result of this, if RPi.GPIO detects that a
# pin has been configured to something other than
# the default (input), you get a warning when you
# try to configure a script. To disable these warnings:
GPIO.setwarnings(False)
# set up GPIO using BCM numbering
GPIO.setmode(GPIO.BCM)



############################################################################
############################################################################
####################### ADMIN ACCESS RESTRICTIONS ##########################
############################################################################
############################################################################

# found with help of @MyTelegramID_bot
ADMINS = [285956437] # mine ID

####################### ADMIN CHECKING #############################################
# @bot.message_handler(commands=['admin'])
# def admin_test(message):
#     sender_ID = message.chat.id
#     # good to turn this to decorator
#     if sender_ID not in ADMINS:
#         bot.send_message(sender_ID, 'Go f*ck youtself *!@&%$^(#)@%:(')
#         return
#     return bot.send_message(sender_ID, 'Админ!!!')


############################################################################
############################################################################
####################### MENU ###############################################
############################################################################
############################################################################

# current BOT ID
chat_id = 285956437

def show_menu():
    keyboard = telebot.types.InlineKeyboardMarkup()
    state_button = telebot.types.InlineKeyboardButton(text='System state', callback_data='state')
    temp_button = telebot.types.InlineKeyboardButton(text='Temperature/Humidity', callback_data='temp')
    light_button = telebot.types.InlineKeyboardButton(text='Switch lights on/off', callback_data='light')
    keyboard.add(state_button)
    keyboard.add(temp_button)
    keyboard.add(light_button)
    bot.send_message(chat_id, 'Menu', reply_markup=keyboard)


@bot.callback_query_handler(func=lambda call: True)
def callback_inline(call):
    if call.data == "state":
        show_system_state(call.message.chat.id)
    if call.data == "temp":
        show_temperature(call.message.chat.id)
    if call.data == "light":
        make_light(call.message.chat.id)


############################################################################
############################################################################
####################### Bot Commands Handlers###############################
############################################################################
############################################################################



####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Привет bitch!')
    show_menu()




####################### STATE ##############################################
def show_system_state(reply_to_ID):
    bot.send_message(reply_to_ID, '-------------- System state ---------------')
    sysname = os.uname().sysname
    release = os.uname().release
    machine = os.uname().machine
    bot.send_message(reply_to_ID, 'OS > ' + sysname + ' ' + release + ' ' + machine)

    bot.send_message(reply_to_ID, 'Date@Time > ' + time.strftime('%a %d-%m-%y @ %H:%M'))

    uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    uptime_time = int(float(uptime))
    uptime_hrs = math.floor(uptime_time / 3600)
    uptime_mins = math.floor((uptime_time % 3600) / 60)

    bot.send_message(reply_to_ID, 'Uptime > ' + str(uptime_hrs) + 'hrs ' + str(uptime_mins) + 'mins')

    df_data = os.popen('df -h /')
    line = df_data.readline()
    line = df_data.readline()
    disk_data = line.split()[0:6]
    # ['/dev/root', '15G', '4.9G', '8.9G', '36%', '/']
    bot.send_message(reply_to_ID, 'Total space  > ' + disk_data[1])
    bot.send_message(reply_to_ID, 'Free space  > ' + disk_data[3])

    core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')
    bot.send_message(reply_to_ID, 'Core temperature > ' + core_temp)

    rtc = open('/sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon0/temp1_input', 'r')
    rtc_data = rtc.read()
    rtc_temp = int(rtc_data)/1000
    bot.send_message(reply_to_ID, 'RTC Temperature = ' + str(rtc_temp) + '°C')

    show_menu()

@bot.message_handler(commands=['state'])
def get_system_state(message):
    show_system_state(message.chat.id)




####################### TEMPERATURE/HUMIDITY ###############################
dht22_pin = 17
dht11_pin = 27

def show_temperature(reply_to_ID):
    humidity22, temperature22 = Adafruit_DHT.read_retry(22, dht22_pin)
    humidity11, temperature11 = Adafruit_DHT.read_retry(11, dht11_pin)

    bot.send_message(reply_to_ID, '------------------ DHT_22 ------------------------')

    if humidity22 is not None and temperature22 is not None:
        bot.send_message(reply_to_ID, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature22, humidity22))
        bot.send_message(reply_to_ID, 'DHT 22 подгорел, влажность некорректна :(')
    else:
        bot.send_message(reply_to_ID, 'Не удалось снять показания сенсора, попробуй через время')
        sys.exit(1)

    bot.send_message(reply_to_ID, '------------------ DHT_11 -------------------------')
    if humidity11 is not None and temperature11 is not None:
        bot.send_message(reply_to_ID, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature11, humidity11))
    else:
        bot.send_message(reply_to_ID, 'Не удалось снять показания сенсора, попробуй через время')
        sys.exit(1)

    show_menu()


@bot.message_handler(commands=['temp'])
def get_temperature(message):
    show_temperature(message.chat.id)



####################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def get_photo(message):
    bot.send_message(message.chat.id, 'Ищу свежую фотку...')
    try:
        recent_photo = open('/home/pi/box_recent_photo.jpg', 'rb')
    except Exception:
        bot.send_message(message.chat.id, 'Сейчас занят, попробуй позже =\ ')
    else:
        bot.send_message(message.chat.id, 'Держи =) ')
        bot.send_photo(message.chat.id, recent_photo)

    show_menu()




####################### LIGHTS #############################################
# all BCM numbers of corresponding lights
lights = [23, 24]
# set OUT MODE for all PINs with light
GPIO.setup(lights, GPIO.OUT)

def make_light(reply_to_ID):
    # switch all illumination according to first light
    if GPIO.input(lights[0]) == 1:
        bot.send_message(reply_to_ID, 'Выключаем... :(')
        GPIO.output(lights, 0)
    else:
        bot.send_message(reply_to_ID, ':) Включаем!!!')
        GPIO.output(lights, 1)

    time.sleep(3)
    show_menu()

@bot.message_handler(commands=['light'])
def switch_light(message):
    make_light(message.chat.id)



####################### REBOOT #############################################
@bot.message_handler(commands=['reboot'])
def reboot(message):
    sender_ID = message.chat.id
    if sender_ID not in ADMINS:
        bot.send_message(sender_ID, 'Go f*ck youtself *!@&%$^(#)@%:(')
        return
    bot.send_message(sender_ID, 'Перезагружаюсь -> ')
    os.system('sudo reboot')
    time.sleep(1)



# ####################### TURN OFF #############################################
@bot.message_handler(commands=['shutdown'])
def shutdown(message):
    sender_ID = message.chat.id
    if sender_ID not in ADMINS:
        bot.send_message(sender_ID, 'Go f*ck youtself *!@&%$^(#)@%:(')
        return
    bot.send_message(sender_ID, 'Выключаюсь =\ ')
    os.system('sudo shutdown -h now')
    time.sleep(1)




############################################################################
############################################################################
############################################################################

bot.polling()
