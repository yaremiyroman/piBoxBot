# -*- coding: utf-8 -*-
import time 
import sqlite3
import RPi.GPIO as GPIO
import Adafruit_DHT
from config import config 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
# GPIO.setup(config.dht_22_1, GPIO.IN)

# sensor_DHT_11 = Adafruit_DHT.DHT11
sensor = Adafruit_DHT.DHT22

sensorsDB = sqlite3.connect(config.sensorsDB)

while True:
    ### DHT22_1
    time.sleep(config.sensors_timeout)
    dht22_1_h, dht22_1_t = Adafruit_DHT.read_retry(sensor, config.dht_22_1)

    if dht22_1_h is not None and dht22_1_t is not None:
        query = "INSERT INTO dht22_1 (t, h) VALUES(" + str(round(dht22_1_t, 1)) + ", " + str(int(round(dht22_1_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ### DHT22_2
    time.sleep(config.sensors_timeout)
    dht22_2_h, dht22_2_t = Adafruit_DHT.read_retry(sensor, config.dht_22_2)

    if dht22_2_h is not None and dht22_2_t is not None:
        query = "INSERT INTO dht22_2 (t, h) VALUES(" + str(round(dht22_2_t, 1)) + ", " + str(int(round(dht22_2_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ### DHT22_3
    time.sleep(config.sensors_timeout)
    dht22_3_h, dht22_3_t = Adafruit_DHT.read_retry(sensor, config.dht_22_2)

    if dht22_3_h is not None and dht22_3_t is not None:
        query = "INSERT INTO dht22_3 (t, h) VALUES(" + str(round(dht22_3_t, 1)) + ", " + str(int(round(dht22_3_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ### DHTam2302_1
    time.sleep(config.sensors_timeout)
    dht2302_1_h, dht2302_1_t = Adafruit_DHT.read_retry(sensor, config.dht_22_2)

    if dht2302_1_h is not None and dht2302_1_t is not None:
        query = "INSERT INTO dht2302_1 (t, h) VALUES(" + str(round(dht2302_1_t, 1)) + ", " + str(int(round(dht2302_1_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ### DHTam2302_2
    time.sleep(config.sensors_timeout)
    dht2302_2_h, dht2302_2_t = Adafruit_DHT.read_retry(sensor, config.dht_22_2)

    if dht2302_2_h is not None and dht2302_2_t is not None:
        query = "INSERT INTO dht2302_2 (t, h) VALUES(" + str(round(dht2302_2_t, 1)) + ", " + str(int(round(dht2302_2_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ###
    time.sleep(config.delay)
