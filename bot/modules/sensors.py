# -*- coding: utf-8 -*-
import time 
import sqlite3
import Adafruit_DHT
import RPi.GPIO as GPIO
from config import config 

pause = 10

DHT11 = 24

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(DHT11, GPIO.IN)

DB = sqlite3.connect(config.climate)

#########################################################################

while True:

    ### DHT11
    dht11_h, dht11_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, DHT11)

    if dht11_h is not None and dht11_t is not None:
        query = "INSERT INTO dht11 (t, h) VALUES(" + str(round(dht11_t, 1)) + ", " + str(int(round(dht11_h))) + ")"
        DB.execute(query)
        DB.commit()
    
    time.sleep(pause)

DB.close()

    # ### DHT11_1
    # cur.execute("SELECT date_time, t, h FROM dht11_1 WHERE id IN (SELECT MAX(id) FROM dht11_1)")
    # dht11_1_data = cur.fetchone()
    # dht11_1_time = str(dht11_1_data[0])
    # dht11_1_temp = str(dht11_1_data[1])
    # dht11_1_humid = str(dht11_1_data[2])
    # bot.send_message(senderID, '🎛 > dht11_1 ⏱ > ' + dht11_1_time + ' 🌡 > ' + dht11_1_temp + '℃' + ' 💧 > ' + dht11_1_humid + '%')
    # time.sleep(delay)

    # ### DHT11_2
    # cur.execute("SELECT date_time, t, h FROM dht11_2 WHERE id IN (SELECT MAX(id) FROM dht11_2)")
    # dht11_2_data = cur.fetchone()
    # dht11_2_time = str(dht11_2_data[0])
    # dht11_2_temp = str(dht11_2_data[1])
    # dht11_2_humid = str(dht11_2_data[2])
    # bot.send_message(senderID, '🎛 > dht11_2 ⏱ > ' + dht11_2_time + ' 🌡 > ' + dht11_2_temp + '℃' + ' 💧 > ' + dht11_2_humid + '%')
    # time.sleep(delay)

    # ### DHT11_3 
    # cur.execute("SELECT date_time, t, h FROM dht11_3 WHERE id IN (SELECT MAX(id) FROM dht11_3)")
    # dht11_3_data = cur.fetchone()
    # dht11_3_time = str(dht11_3_data[0])
    # dht11_3_temp = str(dht11_3_data[1])
    # dht11_3_humid = str(dht11_3_data[2])
    # bot.send_message(senderID, '🎛 > dht11_3 ⏱ > ' + dht11_3_time + ' 🌡 > ' + dht11_3_temp + '℃' + ' 💧 > ' + dht11_3_humid + '%')
    # time.sleep(delay)

    # ### DHT11_4
    # cur.execute("SELECT date_time, t, h FROM dht11_4 WHERE id IN (SELECT MAX(id) FROM dht11_4)")
    # dht11_4_data = cur.fetchone()
    # dht11_4_time = str(dht11_4_data[0])
    # dht11_4_temp = str(dht11_4_data[1])
    # dht11_4_humid = str(dht11_4_data[2])
    # bot.send_message(senderID, '🎛 > dht11_4 ⏱ > ' + dht11_4_time + ' 🌡 > ' + dht11_4_temp + '℃' + ' 💧 > ' + dht11_4_humid + '%')
    # time.sleep(delay)
    
        
    # ### DS18b20
    # cur.execute("SELECT date_time, t FROM ds18b20 WHERE id IN (SELECT MAX(id) FROM ds18b20)")
    # ds18b20_data = cur.fetchone()
    # ds18b20_time = str(ds18b20_data[0])
    # ds18b20 = str(ds18b20_data[1])
    # bot.send_message(senderID, '🎛 > ds18b20 ⏱ > ' + ds18b20_time + ' 🌡 > ' + ds18b20 + '℃')
    # time.sleep(delay)
