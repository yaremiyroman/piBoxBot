# -*- coding: utf-8 -*-
import sys
import config
import telebot
import RPi.GPIO as GPIO
import Adafruit_DHT


############################################################################
############################################################################
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
def make_photo(message):
    bot.send_message(message.chat.id, 'Захватываю...')
    bot.send_message(message.chat.id, 'Фотка готова =) ')




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
