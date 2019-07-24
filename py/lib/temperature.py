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

####################### TEMPERATURE/HUMIDITY ###############################
# dht22_pin = 17
# dht11_pin = 27

# def show_temperature(reply_to_ID):
#     humidity22, temperature22 = Adafruit_DHT.read_retry(22, dht22_pin)
#     humidity11, temperature11 = Adafruit_DHT.read_retry(11, dht11_pin)

#     bot.send_message(reply_to_ID, '------------------ DHT_22 ------------------------')

#     if humidity22 is not None and temperature22 is not None:
#         bot.send_message(reply_to_ID, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature22, humidity22))
#     else:
#         bot.send_message(reply_to_ID, 'Не удалось снять показания сенсора, попробуй через время')
#         sys.exit(1)

#     bot.send_message(reply_to_ID, '------------------ DHT_11 -------------------------')
#     if humidity11 is not None and temperature11 is not None:
#         bot.send_message(reply_to_ID, 'Температура={0:0.1f}*  Влажность={1:0.1f}%'.format(temperature11, humidity11))
#     else:
#         bot.send_message(reply_to_ID, 'Не удалось снять показания сенсора, попробуй через время')
#         sys.exit(1)

#     show_menu()


# @bot.message_handler(commands=['temp'])
# def get_temperature(message):
#     show_temperature(message.chat.id)
