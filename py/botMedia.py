# -*- coding: utf-8 -*-
import os
import time
import telebot

import config

#########################################################################
####################### INIT ###############################################
############################################################################

bot = telebot.TeleBot(config.token)
ADMINS = [config.adminID]

############################################################################
####################### BOT COMMANDS HANDLERS ##############################
############################################################################

####################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    chatID = message.chat.id

    bot.send_message(chatID, 'piMedia: Recent photo --> ')
    
    # try:
    #     os.system('scp pi@piMedia.local:/home/pi/Pictures/cam1.jpg /home/pi/piBoxBot/media/')
    #     time.sleep(3)
    #     recent_photo = open('/home/pi/piBoxBot/media/cam1.jpg', 'rb')
    #     time.sleep(3)
    # except Exceptn:
    #     bot.send_message(chatID, 'Try later :( ')
    # else:
    #     bot.send_photo(chatID, recent_photo)

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        bot.stop_polling()
        time.sleep(10)
        telegram_polling()

telegram_polling()
