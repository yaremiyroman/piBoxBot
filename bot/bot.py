# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import sqlite3
from config import config

############################################################################
######################## INIT ##############################################
############################################################################

bot = telebot.TeleBot(config.token)

############################################################################
######################## MODULES ###########################################
############################################################################

####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Hi bitch!')

####################### STATE ##############################################
@bot.message_handler(commands=['state'])
def show_system_state(message):
    senderID = message.chat.id
    
    bot.send_message(senderID, '✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩')
    bot.send_message(senderID, '✩✩✩✩✩✩✩✩✩✩✩✩ System state ✩✩✩✩✩✩✩✩✩✩✩✩')

    bot.send_message(senderID, '✩ ' + time.strftime('%a %d-%m-%y @ %H:%M'))
    
    sysname, hostname, release, date, core = os.uname()
    bot.send_message(senderID, '✩ OS > ' + sysname + ' ' + release + ' on ' + hostname + ' ')
    
    # TODO use 'uptime'
    uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    uptime_time = int(float(uptime))
    uptime_hrs = math.floor(uptime_time / 3600)
    uptime_mins = math.floor((uptime_time % 3600) / 60)
    bot.send_message(senderID, '✩ Uptime > ' + str(int(uptime_hrs)) + 'hr ' + str(int(uptime_mins)) + 'min')

    df_data = os.popen('df -h /')
    line = df_data.readline()
    line = df_data.readline()
    disk_data = line.split()[0:6]
    bot.send_message(senderID, '✩ Free space  > ' + disk_data[3])

    core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')
    bot.send_message(senderID, '✩ Core temperature > ' + core_temp)

    throttling = os.popen('vcgencmd get_throttled').readline().replace('throttled=','')
    bot.send_message(senderID, '✩ Throttling > ' + throttling)
    
    bot.send_message(senderID, '✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩')

##################### CLIMATE ##############################################
# @bot.message_handler(commands=['climate'])
# def climate(message):
#     senderID = message.chat.id
    
#     ### ########################################################################
#     ### RPi sensors ############################################################
#     bot.send_message(senderID, '### RPi sensors #####################################')
#     sensorsDB = sqlite3.connect(config.sensorsDB)
#     sensorsCur = sensorsDB.cursor()
    
#     ### ########################################################################
#     ### DHT22_1
#     try:
#         bot.send_message(senderID, '✩✩✩ dht22#1 ✩✩✩ ')
#         bot.send_message(senderID, '# reading dht22#1...')
#         time.sleep(3)
#         bot.send_message(senderID, '# reading dht22#1.....')
#         sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht22_1 WHERE id IN (SELECT MAX(id) FROM dht22_1)")
#         dht22_1_data = sensorsCur.fetchone()
#         dht22_1_datetime = str(dht22_1_data[0]).split(' ')
#         dht22_1_time = dht22_1_datetime[1]
#         dht22_1_temp = str(dht22_1_data[1])
#         dht22_1_humid = str(dht22_1_data[2])
#         bot.send_message(senderID, '- done -')
#     except:
#         bot.send_message(senderID, '- sensor error....... -')
#     time.sleep(1)

#     ### DHT22_2
#     try:
#         bot.send_message(senderID, '✩✩✩ dht22#2 ✩✩✩ ')
#         bot.send_message(senderID, '# reading dht22#2...')
#         time.sleep(3)
#         bot.send_message(senderID, '# reading dht22#2.....')
#         sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht22_2 WHERE id IN (SELECT MAX(id) FROM dht22_2)")
#         dht22_2_data = sensorsCur.fetchone()
#         dht22_2_datetime = str(dht22_2_data[0]).split(' ')
#         dht22_2_time = dht22_2_datetime[1]
#         dht22_2_temp = str(dht22_2_data[1])
#         dht22_2_humid = str(dht22_2_data[2])
#         bot.send_message(senderID, '- done -')
#     except:
#         bot.send_message(senderID, '- sensor error....... -')
#     time.sleep(1)

#     ### DHT22_3
#     try:
#         bot.send_message(senderID, '✩✩✩ dht22#3 ✩✩✩ ')
#         bot.send_message(senderID, '# reading dht22#3...')
#         time.sleep(3)
#         bot.send_message(senderID, '# reading dht22#3.....')
#         sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht22_3 WHERE id IN (SELECT MAX(id) FROM dht22_3)")
#         dht22_3_data = sensorsCur.fetchone()
#         dht22_3_datetime = str(dht22_3_data[0]).split(' ')
#         dht22_3_time = dht22_3_datetime[1]
#         dht22_3_temp = str(dht22_3_data[1])
#         dht22_3_humid = str(dht22_3_data[2])
#         bot.send_message(senderID, '- done -')
#     except:
#         bot.send_message(senderID, '- sensor error....... -')
#     time.sleep(1)

#     ### ########################################################################
#     ### DHTam2302_1
#     try:
#         bot.send_message(senderID, '✩✩✩ dht2302#1 ✩✩✩ ')
#         bot.send_message(senderID, '# reading dht2302#1...')
#         time.sleep(3)
#         bot.send_message(senderID, '# reading dht2302#1.....')
#         sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht2302_1 WHERE id IN (SELECT MAX(id) FROM dht2302_1)")
#         dht2302_1_data = sensorsCur.fetchone()
#         dht2302_1_datetime = str(dht2302_1_data[0]).split(' ')
#         dht2302_1_time = dht2302_1_datetime[1]
#         dht2302_1_temp = str(dht2302_1_data[1])
#         dht2302_1_humid = str(dht2302_1_data[2])
#         bot.send_message(senderID, '- done -')
#     except:
#         bot.send_message(senderID, '- sensor error....... -')
#     time.sleep(1)

#     ### DHTam2302_2
#     try:
#         bot.send_message(senderID, '✩✩✩ dht2302#2 ✩✩✩ ')
#         bot.send_message(senderID, '# reading dht2302#2...')
#         time.sleep(3)
#         bot.send_message(senderID, '# reading dht2302#2.....')
#         sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht2302_2 WHERE id IN (SELECT MAX(id) FROM dht2302_2)")
#         dht2302_2_data = sensorsCur.fetchone()
#         dht2302_2_datetime = str(dht2302_2_data[0]).split(' ')
#         dht2302_2_time = dht2302_2_datetime[1]
#         dht2302_2_temp = str(dht2302_2_data[1])
#         dht2302_2_humid = str(dht2302_2_data[2])
#         bot.send_message(senderID, '- done -')
#     except:
#         bot.send_message(senderID, '- sensor error....... -')
#     time.sleep(1)

#     ### ########################################################################
#     ### Sensors Response #######################################################
#     bot.send_message(senderID, '### ')
#     bot.send_message(senderID, '### THE WEATHER IS GOOD ')
#     bot.send_message(senderID, '🎛  DHT₂₂#1  ⏱ ' + dht22_1_time + '  🌡 > ' + dht22_1_temp + '°' + ' 💧 > ' + dht22_1_humid + '%')
#     bot.send_message(senderID, '🎛  DHT₂₂#2  ⏱ ' + dht22_2_time + '  🌡 > ' + dht22_2_temp + '°' + ' 💧 > ' + dht22_2_humid + '%')
#     bot.send_message(senderID, '🎛  DHT₂₂#3  ⏱ ' + dht22_3_time + '  🌡 > ' + dht22_3_temp + '°' + ' 💧 > ' + dht22_3_humid + '%')
#     bot.send_message(senderID, '🎛 DHT₂₃₀₂#1 ⏱ ' + dht2302_1_time + '  🌡 > ' + dht2302_1_temp + '°' + ' 💧 > ' + dht2302_1_humid + '%')
#     bot.send_message(senderID, '🎛 DHT₂₃₀₂#2 ⏱ ' + dht2302_2_time + '  🌡 > ' + dht2302_2_temp + '°' + ' 💧 > ' + dht2302_2_humid + '%')
    
#     ### ########################################################################
#     ### DB post request ########################################################
#     sensorsDB.close()
#     time.sleep(config.delay)

####################### REBOOT #############################################
@bot.message_handler(commands=['reboot'])
def reboot(message):
    senderID = message.chat.id
    if senderID != config.adminID:
        bot.send_message(senderID, 'Go f*ck yourself')
        return
    bot.send_message(senderID, 'Rebooting --> ')
    os.system('sudo reboot')
    time.sleep(config.delay)

####################### TURN OFF ###########################################
@bot.message_handler(commands=['shutdown'])
def shutdown(message):
    senderID = message.chat.id
    if senderID != config.adminID:
        bot.send_message(senderID, 'Go f*ck yourself')
        return
    bot.send_message(senderID, 'Going offline...')
    os.system('sudo shutdown -h now')
    time.sleep(config.delay)

############################################################################
######################## POLLING ###########################################
############################################################################

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        bot.stop_polling()
        time.sleep(config.timeout)
        telegram_polling()

telegram_polling()
