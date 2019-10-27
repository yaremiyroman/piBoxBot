# -*- coding: utf-8 -*-
import os
import glob
import time 
import sqlite3
import Adafruit_DHT
import RPi.GPIO as GPIO
from config import config 

pause = 10

DHT22_1 = 17

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(DHT22_1, GPIO.IN)

DB = sqlite3.connect(config.climate)

#########################################################################

while True:

    ### DHT22_1
    dht22_1_h, dht22_1_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT22, DHT22_1)

    if dht22_1_h is not None and dht22_1_t is not None:
        query = "INSERT INTO dht22_1 (t, h) VALUES(" + str(dht22_1_t) + ", " + str(dht22_1_h) + ")"
        DB.execute(query)
        DB.commit()
    
    time.sleep(pause)

DB.close()
