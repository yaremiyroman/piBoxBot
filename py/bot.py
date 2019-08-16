# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import sqlite3

import config

#########################################################################
####################### INIT ###############################################
############################################################################

bot = telebot.TeleBot(config.token)
ADMINS = [config.adminID]

############################################################################
####################### BOT COMMANDS HANDLERS ##############################
############################################################################

####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Привет bitch!')

####################### STATE ##############################################
@bot.message_handler(commands=['state'])
def show_system_state(message):
    bot.send_message(message.chat.id, 'State here bitch!')
    # sysname = os.uname().sysname
    # release = os.uname().release
    # machine = os.uname().machine

    # uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    # uptime_time = int(float(uptime))
    # uptime_hrs = math.floor(uptime_time / 3600)
    # uptime_mins = math.floor((uptime_time % 3600) / 60)

    # df_data = os.popen('df -h /')
    # line = df_data.readline()
    # line = df_data.readline()
    # disk_data = line.split()[0:6]

    # core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')
    # throttling = os.popen('vcgencmd get_throttled').readline().replace('throttled=','')

    # bot.send_message(message.chat.id, '-------------- System state ---------------')
    # bot.send_message(message.chat.id, 'OS > ' + sysname + ' ' + release + ' ' + machine)
    # bot.send_message(message.chat.id, 'Date@Time > ' + time.strftime('%a %d-%m-%y @ %H:%M'))
    # bot.send_message(message.chat.id, 'Uptime > ' + str(uptime_hrs) + ' hr ' + str(uptime_mins) + ' min')
    # bot.send_message(message.chat.id, 'Free space  > ' + disk_data[3])
    # bot.send_message(message.chat.id, 'Core temperature > ' + core_temp)
    # bot.send_message(message.chat.id, 'Throttling > ' + throttling)

####################### CLIMATE ##############################################
@bot.message_handler(commands=['climate'])
def climate(message):
    conn = sqlite3.connect(config.unoClimateDB)
    cur = conn.cursor()
    time.sleep(1)

    cur.execute("SELECT date_time, t, h FROM dht11_1 WHERE id IN (SELECT MAX(id) FROM dht11_1)")
    dht11_1_data = cur.fetchone()
    dht11_1_time = str(dht11_1_data[0])
    dht11_1_temp = str(dht11_1_data[1])
    dht11_1_humid = str(dht11_1_data[2])
    bot.send_message(message.chat.id, 'dht11_1 @ ' + dht11_1_time + ' > t = ' + dht11_1_temp + '^C' + ' > h = ' + dht11_1_humid + '%')
    time.sleep(1)

    cur.execute("SELECT date_time, t, h FROM dht11_2 WHERE id IN (SELECT MAX(id) FROM dht11_2)")
    dht11_2_data = cur.fetchone()
    dht11_2_time = str(dht11_2_data[0])
    dht11_2_temp = str(dht11_2_data[1])
    dht11_2_humid = str(dht11_2_data[2])
    bot.send_message(message.chat.id, 'dht11_2 @ ' + dht11_2_time + ' > t = ' + dht11_2_temp + '^C' + ' > h = ' + dht11_2_humid + '%')
    time.sleep(1)

    cur.execute("SELECT date_time, t, h FROM dht11_3 WHERE id IN (SELECT MAX(id) FROM dht11_3)")
    dht11_3_data = cur.fetchone()
    dht11_3_time = str(dht11_3_data[0])
    dht11_3_temp = str(dht11_3_data[1])
    dht11_3_humid = str(dht11_3_data[2])
    bot.send_message(message.chat.id, 'dht11_3 @ ' + dht11_3_time + ' > t = ' + dht11_3_temp + '^C' + ' > h = ' + dht11_3_humid + '%')
    time.sleep(1)

    cur.execute("SELECT date_time, t, h FROM dht11_4 WHERE id IN (SELECT MAX(id) FROM dht11_4)")
    dht11_4_data = cur.fetchone()
    dht11_4_time = str(dht11_4_data[0])
    dht11_4_temp = str(dht11_4_data[1])
    dht11_4_humid = str(dht11_4_data[2])
    bot.send_message(message.chat.id, 'dht11_4 @ ' + dht11_4_time + ' > t = ' + dht11_4_temp + '^C' + ' > h = ' + dht11_4_humid + '%')
    time.sleep(1)

    cur.execute("SELECT date_time, t, h FROM dht22_1 WHERE id IN (SELECT MAX(id) FROM dht22_1)")
    dht22_1_data = cur.fetchone()
    dht22_1_time = str(dht22_1_data[0])
    dht22_1_temp = str(dht22_1_data[1])
    dht22_1_humid = str(dht22_1_data[2])
    bot.send_message(message.chat.id, 'dht22_1 @ ' + dht22_1_time + ' > t = ' + dht22_1_temp + '^C' + ' > h = ' + dht22_1_humid + '%')
    time.sleep(1)

    conn.close()
    time.sleep(3)

# ####################### PHOTO ##############################################
# @bot.message_handler(commands=['photo'])
# def photo(message):
#     chatID = message.chat.id

#     bot.send_message(chatID, 'Recent photo --> ')
    
#     try:
#         os.system('scp pi@piMedia.local:/home/pi/Pictures/cam1.jpg /home/pi/piBoxBot/media/')
#         time.sleep(3)
#         recent_photo = open('/home/pi/piBoxBot/media/cam1.jpg', 'rb')
#         time.sleep(3)
#     except Exception:
#         bot.send_message(chatID, 'Try later :( ')
#     else:
#         bot.send_photo(chatID, recent_photo)

####################### REBOOT #############################################
@bot.message_handler(commands=['reboot'])
def reboot(message):
    if chatID not in ADMINS:
        bot.send_message(chatID, 'Go f*ck yourself')
        return
    bot.send_message(chatID, 'Rebooting --> ')
    os.system('sudo reboot')
    time.sleep(1)

# ####################### TURN OFF #############################################
@bot.message_handler(commands=['shutdown'])
def shutdown(message):
    chatID = message.chat.id
    if chatID not in ADMINS:
        bot.send_message(chatID, 'Go f*ck yourself')
        return
    bot.send_message(chatID, 'Going offline...')
    os.system('sudo shutdown -h now')
    time.sleep(1)

############################################################################

############################################################################
###################### POLLING ########################################
############################################################################

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        bot.stop_polling()
        time.sleep(10)
        telegram_polling()

telegram_polling()
