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
    
    ### DHT22_1
    cur.execute("SELECT date_time, t, h FROM dht22_1 WHERE id IN (SELECT MAX(id) FROM dht22_1)")
    dht22_1_data = cur.fetchone()
    dht22_1_time = str(dht22_1_data[0])
    dht22_1_temp = str(dht22_1_data[1])
    dht22_1_humid = str(dht22_1_data[2])
    bot.send_message(senderID, '🎛 > dht22_1 ⏱ > ' + dht22_1_time + ' 🌡 > ' + dht22_1_temp + '℃' + ' 💧 > ' + dht22_1_humid + '%')
    
    ### DHT11_1
    cur.execute("SELECT date_time, t, h FROM dht11_1 WHERE id IN (SELECT MAX(id) FROM dht11_1)")
    dht11_1_data = cur.fetchone()
    dht11_1_time = str(dht11_1_data[0])
    dht11_1_temp = str(dht11_1_data[1])
    dht11_1_humid = str(dht11_1_data[2])
    bot.send_message(senderID, '🎛 > dht11_1 ⏱ > ' + dht11_1_time + ' 🌡 > ' + dht11_1_temp + '℃' + ' 💧 > ' + dht11_1_humid + '%')
    
    ### DHT11_2
    cur.execute("SELECT date_time, t, h FROM dht11_2 WHERE id IN (SELECT MAX(id) FROM dht11_2)")
    dht11_2_data = cur.fetchone()
    dht11_2_time = str(dht11_2_data[0])
    dht11_2_temp = str(dht11_2_data[1])
    dht11_2_humid = str(dht11_2_data[2])
    bot.send_message(senderID, '🎛 > dht11_2 ⏱ > ' + dht11_2_time + ' 🌡 > ' + dht11_2_temp + '℃' + ' 💧 > ' + dht11_2_humid + '%')
    
    ### DHT11_3
    cur.execute("SELECT date_time, t, h FROM dht11_3 WHERE id IN (SELECT MAX(id) FROM dht11_3)")
    dht11_3_data = cur.fetchone()
    dht11_3_time = str(dht11_3_data[0])
    dht11_3_temp = str(dht11_3_data[1])
    dht11_3_humid = str(dht11_3_data[2])
    bot.send_message(senderID, '🎛 > dht11_3 ⏱ > ' + dht11_3_time + ' 🌡 > ' + dht11_3_temp + '℃' + ' 💧 > ' + dht11_3_humid + '%')
    
    ### DHT11_4
    cur.execute("SELECT date_time, t, h FROM dht11_4 WHERE id IN (SELECT MAX(id) FROM dht11_4)")
    dht11_4_data = cur.fetchone()
    dht11_4_time = str(dht11_4_data[0])
    dht11_4_temp = str(dht11_4_data[1])
    dht11_4_humid = str(dht11_4_data[2])
    bot.send_message(senderID, '🎛 > dht11_4 ⏱ > ' + dht11_4_time + ' 🌡 > ' + dht11_4_temp + '℃' + ' 💧 > ' + dht11_4_humid + '%')
    
    ### moisture_1
    # cur.execute("SELECT date_time, h FROM moisture_1 WHERE id IN (SELECT MAX(id) FROM moisture_1)")
    # moisture_1_data = cur.fetchone()
    # moisture_1_time = str(moisture_1_data[0])
    # moisture_1_humid = str(moisture_1_data[1])
    # bot.send_message(senderID, '🎛 > moisture_1 ⏱ > ' + moisture_1_time + ' 💧 > ' + moisture_1_humid + '%')
    
    # ### moisture_2
    # cur.execute("SELECT date_time, h FROM moisture_2 WHERE id IN (SELECT MAX(id) FROM moisture_2)")
    # moisture_2_data = cur.fetchone()
    # moisture_2_time = str(moisture_2_data[0])
    # moisture_2_humid = str(moisture_2_data[1])
    # bot.send_message(senderID, '🎛 > moisture_2 ⏱ > ' + moisture_2_time + ' 💧 > ' + moisture_2_humid + '%')
    
    # ### moisture_3
    # cur.execute("SELECT date_time, h FROM moisture_3 WHERE id IN (SELECT MAX(id) FROM moisture_3)")
    # moisture_3_data = cur.fetchone()
    # moisture_3_time = str(moisture_3_data[0])
    # moisture_3_humid = str(moisture_3_data[1])
    # bot.send_message(senderID, '🎛 > moisture_3 ⏱ > ' + moisture_3_time + ' 💧 > ' + moisture_3_humid + '%')

    conn.close()
    time.sleep(3)

######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    senderID = message.chat.id

    bot.send_message(senderID, 'Recent photo --> ')
    
    try:
        recent_photo = open('/home/pi/cam_telebot.jpg', 'rb')
        time.sleep(3)
    except Exception:
        bot.send_message(senderID, 'Try later :( ')
    else:
        bot.send_photo(senderID, recent_photo)

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    bot.send_message(message.chat.id, 'Lights switching.')
    
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

# ####################### TURN OFF #############################################
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
