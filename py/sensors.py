# -*- coding: utf-8 -*-
import time 
import sqlite3
import RPi.GPIO as GPIO
import Adafruit_DHT
from config import config 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(config.dht_11, GPIO.IN)

while True:
    sensorsDB = sqlite3.connect(config.sensorsDB)
    time.sleep(config.delay)

    ### DHT11
    time.sleep(config.sensors_timeout)
    dht11_h, dht11_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, config.dht_11)

    if dht11_h is not None and dht11_t is not None:
        query = "INSERT INTO dht11 (t, h) VALUES(" + str(round(dht11_t, 1)) + ", " + str(int(round(dht11_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    time.sleep(config.delay)
    sensorsDB.close()
    time.sleep(config.delay)
