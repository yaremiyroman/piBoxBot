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




####################### ARDUINO 1 #############################################
# def get_analogue_1(reply_to_ID):
#     serial_1 = serial.Serial('/dev/ttyACM0', 9600)
#     # serial_1 = serial.Serial('/dev/ttyUSB0', 9600)
#     bot.send_message(reply_to_ID, 'Arduino #1 data >')
#     bot.send_message(serial_1.readline())
#     bot.send_message('-------------------------------')

#     time.sleep(3)
#     show_menu()
