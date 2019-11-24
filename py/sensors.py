# -*- coding: utf-8 -*-
import time 
import sqlite3
import Adafruit_DHT
import RPi.GPIO as GPIO
from config import config 

pause = 10

DHT11 = 17

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
