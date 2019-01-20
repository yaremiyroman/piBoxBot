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
import serial

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
    # temp_button = telebot.types.InlineKeyboardButton(text='Temperature/Humidity', callback_data='temp')
    # light_button = telebot.types.InlineKeyboardButton(text='Switch lights on/off', callback_data='light')
    # photo_button = telebot.types.InlineKeyboardButton(text='Get recent photo', callback_data='photo')
    # arduino_1_button = telebot.types.InlineKeyboardButton(text='Get analogue data #1', callback_data='arduino1')
    keyboard.add(state_button)
    # keyboard.add(temp_button)
    # keyboard.add(light_button)
    # keyboard.add(photo_button)
    # keyboard.add(arduino_1_button)
    bot.send_message(chat_id, 'Menu', reply_markup=keyboard)


@bot.callback_query_handler(func=lambda call: True)
def callback_inline(call):
    chat_id = call.message.chat.id

    if call.data == "state":
        show_system_state(chat_id)
    # if call.data == "temp":
    #     show_temperature(chat_id)
    # if call.data == "light":
    #     make_light(chat_id)
    # if call.data == "arduino1":
    #     get_analogue_1(chat_id)
    # if call.data == "photo":
    #     open_recent_photo(chat_id)


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
