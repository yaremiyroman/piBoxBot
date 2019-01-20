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


####################### LIGHTS #############################################
# all BCM numbers of corresponding lights
# lights = [23, 24]
# set OUT MODE for all PINs with light
# GPIO.setup(lights, GPIO.OUT)

# def make_light(reply_to_ID):
#     # switch all illumination according to first light
#     if GPIO.input(lights[0]) == 1:
#         bot.send_message(reply_to_ID, 'Выключаем... :(')
#         GPIO.output(lights, 0)
#     else:
#         bot.send_message(reply_to_ID, ':) Включаем!!!')
#         GPIO.output(lights, 1)

#     time.sleep(3)
#     show_menu()

# @bot.message_handler(commands=['light'])
# def switch_light(message):
#     make_light(message.chat.id)
