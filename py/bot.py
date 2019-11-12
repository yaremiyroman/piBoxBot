# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import sqlite3

from config import config 

#########################################################################

delay = 3
pause = 10
bot = telebot.TeleBot(config.token)
adminID = config.adminID

####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Hi bitch!')

####################### STATE ##############################################
@bot.message_handler(commands=['state'])
def show_system_state(message):
    senderID = message.chat.id
    
    bot.send_message(senderID, 'System state > ' + time.strftime('%a %d-%m-%y @ %H:%M'))
    
    sysname, hostname, release, date, core = os.uname()
    bot.send_message(senderID, 'OS > ' + sysname + ' ' + release + ' on ' + hostname + ' ')
    
    # //  move bash scripts to constants 
    uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    uptime_time = int(float(uptime))
    uptime_hrs = math.floor(uptime_time / 3600)
    uptime_mins = math.floor((uptime_time % 3600) / 60)
    bot.send_message(senderID, 'Uptime > ' + str(int(uptime_hrs)) + 'hr ' + str(int(uptime_mins)) + 'min')

    df_data = os.popen('df -h /')
    line = df_data.readline()
    line = df_data.readline()
    disk_data = line.split()[0:6]
    bot.send_message(senderID, 'Free space  > ' + disk_data[3])

    core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')
    bot.send_message(senderID, 'Core temperature > ' + core_temp)

    throttling = os.popen('vcgencmd get_throttled').readline().replace('throttled=','')
    bot.send_message(senderID, 'Throttling > ' + throttling)

###################### CLIMATE ##############################################
@bot.message_handler(commands=['climate'])
def climate(message):
    senderID = message.chat.id
    conn = sqlite3.connect(config.climate)
    cur = conn.cursor()
    time.sleep(delay)
    
    ### DHT11
    cur.execute("SELECT date_time, t, h FROM dht11 WHERE id IN (SELECT MAX(id) FROM dht11)")
    dht11_data = cur.fetchone()
    dht11_time = str(dht11_data[0])
    dht11_temp = str(dht11_data[1])
    dht11_humid = str(dht11_data[2])
    bot.send_message(senderID, '🎛 DHT22 ⏱ ' + dht11_time + ' 🌡 > ' + dht11_temp + '°' + ' 💧 > ' + dht11_humid + '%')
    
    conn.close()
    time.sleep(3)

######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    bot.send_message(message.chat.id, '*** Photo will be available on piMedia ***')

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    bot.send_message(message.chat.id, '*** Lights will be available late r***')
    
####################### REBOOT #############################################
@bot.message_handler(commands=['reboot'])
def reboot(message):
    senderID = message.chat.id
    if senderID <> adminID:
        bot.send_message(senderID, 'Go f*ck yourself')
        return
    bot.send_message(senderID, 'Rebooting --> ')
    os.system('sudo reboot')
    time.sleep(delay)

####################### TURN OFF #############################################
@bot.message_handler(commands=['shutdown'])
def shutdown(message):
    senderID = message.chat.id
    if senderID <> adminID:
        bot.send_message(senderID, 'Go f*ck yourself')
        return
    bot.send_message(senderID, 'Going offline...')
    os.system('sudo shutdown -h now')
    time.sleep(delay)

############################################################################
###################### POLLING ########################################
############################################################################

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        bot.stop_polling()
        time.sleep(pause)
        telegram_polling()

telegram_polling()
