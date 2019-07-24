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

####################### PHOTO ##############################################
# def open_recent_photo(reply_to_ID):
#     bot.send_message(reply_to_ID, 'Ищу свежую фотку...')
#     try:
#         recent_photo = open('/home/pi/box_recent_photo.jpg', 'rb')
#     except Exception:
#         bot.send_message(reply_to_ID, 'Сейчас занят, попробуй позже =\ ')
#     else:
#         bot.send_message(reply_to_ID, 'Держи =) ')
#         bot.send_photo(reply_to_ID, recent_photo)

#     show_menu()

# @bot.message_handler(commands=['photo'])
# def get_photo(message):
#     open_recent_photo(message.chat.id)
