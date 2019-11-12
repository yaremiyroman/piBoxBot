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
    dht11_datetime = str(dht11_data[0]).split(' ')
    dht11_time = dht11_datetime[1]
    dht11_temp = str(dht11_data[1])
    dht11_humid = str(dht11_data[2])
    bot.send_message(senderID, '🎛⏱ dht ' + dht11_time + '  🌡 > ' + dht11_temp + '°' + ' 💧 > ' + dht11_humid + '%')
    
    ### ds18b20
    cur.execute("SELECT date_time, t FROM ds18b20 WHERE id IN (SELECT MAX(id) FROM ds18b20)")
    ds18b20_data = cur.fetchone()
    ds18b20_datetime = str(ds18b20_data[0]).split(' ')
    ds18b20_time = ds18b20_datetime[1]
    ds18b20_temp = str(ds18b20_data[1])
    bot.send_message(senderID, '🎛⏱ ds18 ' + ds18b20_time + '  🌡 > ' + ds18b20_temp + '°')
    
    ### DHT11_1
    cur.execute("SELECT date_time, t, h FROM dht11_1 WHERE id IN (SELECT MAX(id) FROM dht11_1)")
    dht11_1_data = cur.fetchone()
    dht11_1_datetime = str(dht11_1_data[0]).split(' ')
    dht11_1_time = dht11_1_datetime[1]
    dht11_1_temp = str(dht11_1_data[1])
    dht11_1_humid = str(dht11_1_data[2])
    bot.send_message(senderID, '🎛⏱ dht ' + dht11_1_time + '  🌡 > ' + dht11_1_temp + '°' + ' 💧 > ' + dht11_1_humid + '%')
    
    ### DHT11_2
    cur.execute("SELECT date_time, t, h FROM dht11_2 WHERE id IN (SELECT MAX(id) FROM dht11_2)")
    dht11_2_data = cur.fetchone()
    dht11_2_datetime = str(dht11_2_data[0]).split(' ')
    dht11_2_time = dht11_2_datetime[1]
    dht11_2_temp = str(dht11_2_data[1])
    dht11_2_humid = str(dht11_2_data[2])
    bot.send_message(senderID, '🎛⏱ dht ' + dht11_2_time + '  🌡 > ' + dht11_2_temp + '°' + ' 💧 > ' + dht11_2_humid + '%')
    
    ### DHT11_3
    cur.execute("SELECT date_time, t, h FROM dht11_3 WHERE id IN (SELECT MAX(id) FROM dht11_3)")
    dht11_3_data = cur.fetchone()
    dht11_3_datetime = str(dht11_3_data[0]).split(' ')
    dht11_3_time = dht11_3_datetime[1]
    dht11_3_temp = str(dht11_3_data[1])
    dht11_3_humid = str(dht11_3_data[2])
    bot.send_message(senderID, '🎛⏱ dht ' + dht11_3_time + '  🌡 > ' + dht11_3_temp + '°' + ' 💧 > ' + dht11_3_humid + '%')
    
    ### DHT11_4
    cur.execute("SELECT date_time, t, h FROM dht11_4 WHERE id IN (SELECT MAX(id) FROM dht11_4)")
    dht11_4_data = cur.fetchone()
    dht11_4_datetime = str(dht11_4_data[0]).split(' ')
    dht11_4_time = dht11_4_datetime[1]
    dht11_4_temp = str(dht11_4_data[1])
    dht11_4_humid = str(dht11_4_data[2])
    bot.send_message(senderID, '🎛⏱ dht ' + dht11_4_time + '  🌡 > ' + dht11_4_temp + '°' + ' 💧 > ' + dht11_4_humid + '%')
    
    ### moi_1
    cur.execute("SELECT date_time, h FROM moi_1 WHERE id IN (SELECT MAX(id) FROM moi_1)")
    moi_1_data = cur.fetchone()
    moi_1_datetime = str(moi_1_data[0]).split(' ')
    moi_1_time = moi_1_datetime[1]
    moi_1_temp = str(moi_1_data[1])
    bot.send_message(senderID, '🎛⏱ moisture ' + moi_1_time + '  💧 > ' + moi_1_temp + '°')
    
    ### moi_2
    cur.execute("SELECT date_time, h FROM moi_2 WHERE id IN (SELECT MAX(id) FROM moi_2)")
    moi_2_data = cur.fetchone()
    moi_2_datetime = str(moi_2_data[0]).split(' ')
    moi_2_time = moi_2_datetime[1]
    moi_2_temp = str(moi_2_data[1])
    bot.send_message(senderID, '🎛⏱ moisture ' + moi_2_time + '  💧 > ' + moi_2_temp + '°')
    
    ### liquid
    cur.execute("SELECT date_time, lvl FROM liquid WHERE id IN (SELECT MAX(id) FROM liquid)")
    liquid_data = cur.fetchone()
    liquid_datetime = str(liquid_data[0]).split(' ')
    liquid_time = liquid_datetime[1]
    liquid_temp = str(liquid_data[1])
    bot.send_message(senderID, '🎛⏱ liquid ' + liquid_time + '  💧 > ' + liquid_temp)
    
    ### steam
    cur.execute("SELECT date_time, stm FROM steam WHERE id IN (SELECT MAX(id) FROM steam)")
    steam_data = cur.fetchone()
    steam_datetime = str(steam_data[0]).split(' ')
    steam_time = steam_datetime[1]
    steam_temp = str(steam_data[1])
    bot.send_message(senderID, '🎛⏱ steam ' + steam_time + '  💧 > ' + steam_temp)
    
    ### rain
    cur.execute("SELECT date_time, rain FROM rain WHERE id IN (SELECT MAX(id) FROM rain)")
    rain_data = cur.fetchone()
    rain_datetime = str(rain_data[0]).split(' ')
    rain_time = rain_datetime[1]
    rain_temp = str(rain_data[1])
    bot.send_message(senderID, '🎛⏱ rain ' + rain_time + '  💧 > ' + rain_temp)
    
    ### light
    cur.execute("SELECT date_time, light FROM light WHERE id IN (SELECT MAX(id) FROM light)")
    light_data = cur.fetchone()
    light_datetime = str(light_data[0]).split(' ')
    light_time = light_datetime[1]
    light_temp = str(light_data[1])
    bot.send_message(senderID, '🎛⏱ light ' + light_time + '  💧 > ' + light_temp)
    
    conn.close()
    time.sleep(3)

######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    bot.send_message(message.chat.id, '*** Photo will be available on piMedia ***')

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    bot.send_message(message.chat.id, '*** Lights will be available later ***')
    
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
