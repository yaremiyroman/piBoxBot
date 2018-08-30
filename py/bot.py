# -*- coding: utf-8 -*-
import config
import telebot
import RPi.GPIO as GPIO
# from picamera import PiCamera
# from time import sleep



####################### INIT ###############################################
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



####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Привет bitch!')



####################### PHOTO ##############################################
# @bot.message_handler(commands=['photo'])
# def send_welcome(message):
#     msg = bot.send_message(message.chat.id, 'Делаю фото...')
#     camera = PiCamera()
#     camera.capture('/home/pi/Pictures/cam/bot_photo.jpg')



####################### LIGHTS #############################################
# all BCM numbers of corresponding lights
lights = [23, 24]
# set OUT MODE for all PINs with light
GPIO.setup(lights, GPIO.OUT)

@bot.message_handler(commands=['light'])
def switch(message):
    # switch all illumination according to first light
    if GPIO.input(lights[0]) == 1:
        bot.send_message(message.chat.id, 'Выключаем... :(')
        GPIO.output(lights, 0)
    else:
        bot.send_message(message.chat.id, ':) Включаем!!!')
        GPIO.output(lights, 1)



bot.polling()
