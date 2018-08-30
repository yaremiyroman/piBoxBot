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
# import camera

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
####################### Bot Commands Handlers###############################
############################################################################
############################################################################



####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Привет bitch!')




####################### STATE ##############################################
@bot.message_handler(commands=['state'])
def get_system_state(message):
    bot.send_message(message.chat.id, '-------------- System state ---------------')
    sysname = os.uname().sysname
    release = os.uname().release
    machine = os.uname().machine
    bot.send_message(message.chat.id, 'OS > ' + sysname + ' ' + release + ' ' + machine)

    bot.send_message(message.chat.id, 'Date@Time > ' + time.strftime('%a %d-%m-%y @ %H:%M'))

    uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    uptime_time = int(float(uptime))
    uptime_hrs = math.floor(uptime_time / 3600)
    uptime_mins = math.floor((uptime_time % 3600) / 60)

    bot.send_message(message.chat.id, 'Uptime > ' + str(uptime_hrs) + 'hrs ' + str(uptime_mins) + 'mins')

    df_data = os.popen('df -h /')
    line = df_data.readline()
    line = df_data.readline()
    disk_data = line.split()[0:6]
    # ['/dev/root', '15G', '4.9G', '8.9G', '36%', '/']
    bot.send_message(message.chat.id, 'Total space  > ' + disk_data[1])
    bot.send_message(message.chat.id, 'Free space  > ' + disk_data[3])

    core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')
    bot.send_message(message.chat.id, 'Core temperature > ' + core_temp)

    rtc = open('/sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon0/temp1_input', 'r')
    rtc_data = rtc.read()
    rtc_temp = int(rtc_data)/1000
    bot.send_message(message.chat.id, 'RTC Temperature = ' + str(rtc_temp) + '°C')


####################### TEMPERATURE/HUMIDITY ###############################
dht22_pin = 17
dht11_pin = 27

@bot.message_handler(commands=['temp'])
def get_temperature(message):
    humidity22, temperature22 = Adafruit_DHT.read_retry(22, dht22_pin)
    humidity11, temperature11 = Adafruit_DHT.read_retry(11, dht11_pin)

    bot.send_message(message.chat.id, '------------------ DHT_22 ------------------------')
    if humidity22 is not None and temperature22 is not None:
        bot.send_message(message.chat.id, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature22, humidity22))
        bot.send_message(message.chat.id, 'DHT 22 подгорел, влажность некорректна :(')
    else:
        bot.send_message(message.chat.id, 'Не удалось снять показания сенсора, попробуй через время')
        sys.exit(1)

    bot.send_message(message.chat.id, '------------------ DHT_11 -------------------------')
    if humidity11 is not None and temperature11 is not None:
        bot.send_message(message.chat.id, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature11, humidity11))
    else:
        bot.send_message(message.chat.id, 'Не удалось снять показания сенсора, попробуй через время')
        sys.exit(1)




####################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def get_photo(message):
    bot.send_message(message.chat.id, 'Фоткаю...')
    bot.send_message(message.chat.id, 'Фотка готова =) ')
    # camera.one_shot_photo()
    # bot.send_photo(message.chat.id, open('/home/pi/Pictures/cam/box_30_08_18__20_47_24.jpg', 'rb'))


####################### LIGHTS #############################################
# all BCM numbers of corresponding lights
lights = [23, 24]
# set OUT MODE for all PINs with light
GPIO.setup(lights, GPIO.OUT)

@bot.message_handler(commands=['light'])
def switch_light(message):
    # switch all illumination according to first light
    if GPIO.input(lights[0]) == 1:
        bot.send_message(message.chat.id, 'Выключаем... :(')
        GPIO.output(lights, 0)
    else:
        bot.send_message(message.chat.id, ':) Включаем!!!')
        GPIO.output(lights, 1)




############################################################################
############################################################################
############################################################################

bot.polling()
