# -*- coding: utf-8 -*-
import time 
import sqlite3
import RPi.GPIO as GPIO
import Adafruit_DHT
from config import config 

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
# GPIO.setup(config.dht_11, GPIO.IN)
# GPIO.setup(config.dht_22, GPIO.IN)

sensorDHT11 = Adafruit_DHT.DHT22
sensorDHT22 = Adafruit_DHT.DHT22

sensorsDB = sqlite3.connect(config.sensorsDB)

while True:
    ### DHT11
    time.sleep(config.sensors_timeout)
    dht11_h, dht11_t = Adafruit_DHT.read_retry(sensorDHT11, config.dht_11)

    if dht11_h is not None and dht11_t is not None:
        query = "INSERT INTO dht11 (t, h) VALUES(" + str(round(dht11_t, 1)) + ", " + str(int(round(dht11_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    ### DHT22
    time.sleep(config.sensors_timeout)
    dht22_h, dht22_t = Adafruit_DHT.read_retry(sensorDHT22, config.dht_22)

    if dht22_h is not None and dht22_t is not None:
        query = "INSERT INTO dht22 (t, h) VALUES(" + str(round(dht22_t, 1)) + ", " + str(int(round(dht22_h))) + ")"
        sensorsDB.execute(query)
        sensorsDB.commit()
    
    time.sleep(config.delay)
