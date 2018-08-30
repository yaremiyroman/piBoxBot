# -*- coding: utf-8 -*-
import config
import telebot
import RPi.GPIO as GPIO

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
# setup GPIO using Board numbering
# GPIO.setmode(GPIO.BOARD)

# set up LED pins to OUT MODE
# for multiple pins control array can be uase as argument
# example: GPIO.output(lights, 1)
# will turn on all light pins
lights = [23, 24]
GPIO.setup(lights, GPIO.OUT)

light_1 = 23
light_1 = 24

@bot.message_handler(commands=['start', 'help'])
def send_welcome(message):
    msg = bot.send_message(message.chat.id, 'Привет Cука!')

@bot.message_handler(commands=['state'])
def send_welcome(message):
    msg = bot.send_message(message.chat.id, 'Тут будет состояние системы')

@bot.message_handler(commands=['photo'])
def send_welcome(message):
    msg = bot.send_message(message.chat.id, 'Тут будет состояние системы')

@bot.message_handler(commands=['weather'])
def send_welcome(message):
    msg = bot.send_message(message.chat.id, 'Тут будет состояние системы')

@bot.message_handler(commands=['light'])
def send_welcome(message):
    light_state = GPIO.input(light_1)
    if light_state == 1:
        msg = bot.send_message(message.chat.id, 'Выключаем... :(')
        GPIO.output(lights, 0)
    else:
        msg = bot.send_message(message.chat.id, ':) Включаем!!!')
        GPIO.output(lights, 1)

bot.polling()
