# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import sqlite3
from config import config 

bot = telebot.TeleBot(config.token)

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
    
    ### RPi sensors ############################################################
    ############################################################################
    sensorsDB = sqlite3.connect(config.sensorsDB)
    sensorsCur = sensorsDB.cursor()
    
    ### DHT11
    time.sleep(config.delay)
    sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht11 WHERE id IN (SELECT MAX(id) FROM dht11)")
    dht11_data = sensorsCur.fetchone()
    dht11_datetime = str(dht11_data[0]).split(' ')
    dht11_time = dht11_datetime[1]
    dht11_temp = str(dht11_data[1])
    dht11_humid = str(dht11_data[2])
    
    ### DHT22
    time.sleep(config.delay)
    sensorsCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht22 WHERE id IN (SELECT MAX(id) FROM dht22)")
    dht22_data = sensorsCur.fetchone()
    dht22_datetime = str(dht22_data[0]).split(' ')
    dht22_time = dht22_datetime[1]
    dht22_temp = str(dht22_data[1])
    dht22_humid = str(dht22_data[2])
    
    time.sleep(config.delay)
    sensorsDB.close()
    time.sleep(config.delay)
    
    bot.send_message(senderID, '🎛⏱ dht11 ' + dht11_time + '  🌡 > ' + dht11_temp + '°' + ' 💧 > ' + dht11_humid + '%')
    bot.send_message(senderID, '🎛⏱ dht22 ' + dht22_time + '  🌡 > ' + dht22_temp + '°' + ' 💧 > ' + dht22_humid + '%')
    
    ### UNO sensors ############################################################
    ############################################################################
    
    climateDB = sqlite3.connect(config.climateDB)
    climateCur = climateDB.cursor()
    
    ### ds18b20
    time.sleep(config.delay)
    climateCur.execute("SELECT DATETIME(date_time, 'localtime'), t FROM ds18b20 WHERE id IN (SELECT MAX(id) FROM ds18b20)")
    ds18b20_data = climateCur.fetchone()
    ds18b20_datetime = str(ds18b20_data[0]).split(' ')
    ds18b20_time = ds18b20_datetime[1]
    ds18b20 = str(ds18b20_data[1])

    ### DHT1
    time.sleep(config.delay)
    climateCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht1 WHERE id IN (SELECT MAX(id) FROM dht1)")
    dht1_data = climateCur.fetchone()
    dht1_datetime = str(dht1_data[0]).split(' ')
    dht1_time = dht1_datetime[1]
    dht1_temp = str(dht1_data[1])
    dht1_humid = str(dht1_data[2])

    ### DHT2
    time.sleep(config.delay)
    climateCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht2 WHERE id IN (SELECT MAX(id) FROM dht2)")
    dht2_data = climateCur.fetchone()
    dht2_datetime = str(dht2_data[0]).split(' ')
    dht2_time = dht2_datetime[1]
    dht2_temp = str(dht2_data[1])
    dht2_humid = str(dht2_data[2])

    ### DHT3
    time.sleep(config.delay)
    climateCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht3 WHERE id IN (SELECT MAX(id) FROM dht3)")
    dht3_data = climateCur.fetchone()
    dht3_datetime = str(dht3_data[0]).split(' ')
    dht3_time = dht3_datetime[1]
    dht3_temp = str(dht3_data[1])
    dht3_humid = str(dht3_data[2])

    ### DHT4
    time.sleep(config.delay)
    climateCur.execute("SELECT DATETIME(date_time, 'localtime'), t, h FROM dht4 WHERE id IN (SELECT MAX(id) FROM dht4)")
    dht4_data = climateCur.fetchone()
    dht4_datetime = str(dht4_data[0]).split(' ')
    dht4_time = dht4_datetime[1]
    dht4_temp = str(dht4_data[1])
    dht4_humid = str(dht4_data[2])

    # ### light
    # time.sleep(config.delay)
    # climateCur.execute("SELECT DATETIME(date_time, 'localtime'), light FROM light WHERE id IN (SELECT MAX(id) FROM light)")
    # light_data = climateCur.fetchone()
    # light_datetime = str(light_data[0]).split(' ')
    # light_time = light_datetime[1]
    # light = str(light_data[1])
    
    climateDB.close()
    
    bot.send_message(senderID, '🎛⏱ ds18b20 ' + ds18b20_time + '  🌡 > ' + ds18b20 + '°')
    bot.send_message(senderID, '🎛⏱ dht1 ' + dht1_time + '  🌡 > ' + dht1_temp + '°' + ' 💧 > ' + dht1_humid + '%')
    bot.send_message(senderID, '🎛⏱ dht2 ' + dht2_time + '  🌡 > ' + dht2_temp + '°' + ' 💧 > ' + dht2_humid + '%')
    bot.send_message(senderID, '🎛⏱ dht3 ' + dht3_time + '  🌡 > ' + dht3_temp + '°' + ' 💧 > ' + dht3_humid + '%')
    bot.send_message(senderID, '🎛⏱ dht4 ' + dht4_time + '  🌡 > ' + dht4_temp + '°' + ' 💧 > ' + dht4_humid + '%')
    # bot.send_message(senderID, '🎛⏱ lm35 ' + lm35_time + '  🌡 > ' + lm35 + '°')
    # bot.send_message(senderID, '🎛⏱ moisture ' + moi_time + '  💦 > ' + moi)
    # bot.send_message(senderID, '🎛⏱ steam ' + steam_time + '  🌀 > ' + steam)
    # bot.send_message(senderID, '🎛⏱ light ' + light_time + '  🔆 > ' + light)
    
    time.sleep(config.delay)
    
######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    senderID = message.chat.id
    bot.send_message(senderID, 'Recent photo --> ')
    try:
        recent_photo = open('/home/pi/cam.jpg', 'rb')
        time.sleep(3)
    except Exception:
        bot.send_message(senderID, 'Try later :( ')
    else:
        bot.send_photo(senderID, recent_photo)

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    bot.send_message(message.chat.id, '*** Lights will be available later ***')
    
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

####################### TURN OFF #############################################
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
###################### POLLING ########################################
############################################################################

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        bot.stop_polling()
        time.sleep(config.timeout)
        telegram_polling()

telegram_polling()
