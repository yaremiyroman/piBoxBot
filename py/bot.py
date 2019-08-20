# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import sqlite3
import RPi.GPIO as GPIO

from config import config 

#########################################################################
####################### VARS ###########################################
#########################################################################
rest = 1
delay = 3
pause = 10

PIRAHNIA_1 = 5
PIRAHNIA_2 = 6
#########################################################################
####################### INIT ###############################################
############################################################################
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(PIRAHNIA_1, GPIO.OUT)
GPIO.output(PIRAHNIA_1, GPIO.LOW)
GPIO.setup(PIRAHNIA_2, GPIO.OUT)
GPIO.output(PIRAHNIA_2, GPIO.LOW)

bot = telebot.TeleBot(config.token)
adminID = config.adminID

############################################################################
####################### BOT COMMANDS HANDLERS ##############################
############################################################################

####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    senderID = message.chat.id
    bot.send_message(senderID, 'Hi bitch!')

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
    conn = sqlite3.connect(config.unoClimateDB)
    cur = conn.cursor()
    time.sleep(delay)

    ### DHT22_1
    cur.execute("SELECT date_time, t, h FROM dht22_1 WHERE id IN (SELECT MAX(id) FROM dht22_1)")
    dht22_1_data = cur.fetchone()
    dht22_1_time = str(dht22_1_data[0])
    dht22_1_temp = str(dht22_1_data[1])
    dht22_1_humid = str(dht22_1_data[2])
    bot.send_message(senderID, 'dht22_1 @ ' + dht22_1_time + ' > t = ' + dht22_1_temp + '🌡' + ' > h = ' + dht22_1_humid + '%')
    time.sleep(delay)

    ### DHT11_1
    cur.execute("SELECT date_time, t, h FROM dht11_1 WHERE id IN (SELECT MAX(id) FROM dht11_1)")
    dht11_1_data = cur.fetchone()
    dht11_1_time = str(dht11_1_data[0])
    dht11_1_temp = str(dht11_1_data[1])
    dht11_1_humid = str(dht11_1_data[2])
    bot.send_message(senderID, 'dht11_1 @ ' + dht11_1_time + ' > t = ' + dht11_1_temp + '🌡' + ' > h = ' + dht11_1_humid + '%')
    time.sleep(delay)

    ### DHT11_2
    cur.execute("SELECT date_time, t, h FROM dht11_2 WHERE id IN (SELECT MAX(id) FROM dht11_2)")
    dht11_2_data = cur.fetchone()
    dht11_2_time = str(dht11_2_data[0])
    dht11_2_temp = str(dht11_2_data[1])
    dht11_2_humid = str(dht11_2_data[2])
    bot.send_message(senderID, 'dht11_2 @ ' + dht11_2_time + ' > t = ' + dht11_2_temp + '🌡' + ' > h = ' + dht11_2_humid + '%')
    time.sleep(delay)

    ### DHT11_3
    cur.execute("SELECT date_time, t, h FROM dht11_3 WHERE id IN (SELECT MAX(id) FROM dht11_3)")
    dht11_3_data = cur.fetchone()
    dht11_3_time = str(dht11_3_data[0])
    dht11_3_temp = str(dht11_3_data[1])
    dht11_3_humid = str(dht11_3_data[2])
    bot.send_message(senderID, 'dht11_3 @ ' + dht11_3_time + ' > t = ' + dht11_3_temp + '🌡' + ' > h = ' + dht11_3_humid + '%')
    time.sleep(delay)

    ### DHT11_4
    cur.execute("SELECT date_time, t, h FROM dht11_4 WHERE id IN (SELECT MAX(id) FROM dht11_4)")
    dht11_4_data = cur.fetchone()
    dht11_4_time = str(dht11_4_data[0])
    dht11_4_temp = str(dht11_4_data[1])
    dht11_4_humid = str(dht11_4_data[2])
    bot.send_message(senderID, 'dht11_4 @ ' + dht11_4_time + ' > t = ' + dht11_4_temp + '🌡' + ' > h = ' + dht11_4_humid + '%')
    time.sleep(delay)
    
    ### DS18b20
    cur.execute("SELECT date_time, t FROM ds18b20 WHERE id IN (SELECT MAX(id) FROM ds18b20)")
    ds18b20_data = cur.fetchone()
    ds18b20_time = str(ds18b20_data[0])
    ds18b20 = str(ds18b20_data[1])
    bot.send_message(message.chat.id, 'ds18b20 @ ' + ds18b20_time + ' > t = ' + ds18b20 + '🌡')
    time.sleep(delay)
    
    conn.close()
    time.sleep(3)

######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    senderID = message.chat.id

    bot.send_message(senderID, 'Recent photo --> ')
    
    try:
        recent_photo = open('/home/pi/Pictures/cam1.jpg', 'rb')
        time.sleep(3)
    except Exception:
        bot.send_message(senderID, 'Try later :( ')
    else:
        bot.send_photo(senderID, recent_photo)

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    senderID = message.chat.id
    
    if GPIO.input(PIRAHNIA_1) == 0:
        bot.send_message(senderID, 'Turning on...')
        GPIO.output(PIRAHNIA_1, GPIO.HIGH)
        time.sleep(rest)
        GPIO.output(PIRAHNIA_2, GPIO.HIGH)
    else:
        bot.send_message(senderID, 'Lights off!!')
        GPIO.output(PIRAHNIA_1, GPIO.LOW)
        time.sleep(rest)
        GPIO.output(PIRAHNIA_2, GPIO.LOW)

    time.sleep(delay)
    
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
