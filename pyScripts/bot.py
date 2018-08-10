# -*- coding: utf-8 -*-
import config
import telebot

bot = telebot.TeleBot(config.token)

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

bot.polling()
