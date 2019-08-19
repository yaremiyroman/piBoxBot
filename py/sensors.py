# -*- coding: utf-8 -*-
import time
import sqlite3
import Adafruit_DHT
import RPi.GPIO as GPIO
from config import config 

#########################################################################
####################### VARS ###########################################
#########################################################################
pause = 10

DHT22_1 = 24

DHT11_1 = 14
DHT11_2 = 15
DHT11_3 = 18
DHT11_4 = 23

#########################################################################
####################### INIT ###########################################
#########################################################################
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(DHT22_1, GPIO.IN)

GPIO.setup(DHT11_1, GPIO.IN)
GPIO.setup(DHT11_2, GPIO.IN)
GPIO.setup(DHT11_3, GPIO.IN)
GPIO.setup(DHT11_4, GPIO.IN)

DB = sqlite3.connect(config.unoClimateDB)

while True:
    #########################################################################
    ####################### DHT22 ###########################################
    #########################################################################
    
    ### DHT22_1
    dht22_1_h, dht22_1_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT22, DHT22_1)

    if dht22_1_h is not None and dht22_1_t is not None:
        query = "INSERT INTO dht22_1 (t, h) VALUES(" + str(dht22_1_t) + ", " + str(dht22_1_h) + ")"
        DB.execute(query)
        DB.commit()
    
    time.sleep(pause)

    #########################################################################
    ####################### DHT11 ###########################################
    #########################################################################
    
    ### DHT11_1
    dht11_1_h, dht11_1_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, DHT11_1)

    if dht11_1_h is not None and dht11_1_t is not None:
        query = "INSERT INTO dht11_1 (t, h) VALUES(" + str(dht11_1_t) + ", " + str(dht11_1_h) + ")"
        DB.execute(query)
        DB.commit()
    
    time.sleep(pause)

    ### DHT11_2
    dht11_2_h, dht11_2_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, DHT11_2)

    if dht11_2_h is not None and dht11_2_t is not None:
        query = "INSERT INTO dht11_2 (t, h) VALUES(" + str(dht11_2_t) + ", " + str(dht11_2_h) + ")"
        DB.execute(query)
        DB.commit()
                
    time.sleep(pause)

    ### DHT11_3
    dht11_3_h, dht11_3_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, DHT11_3)

    if dht11_3_h is not None and dht11_3_t is not None:
        query = "INSERT INTO dht11_3 (t, h) VALUES(" + str(dht11_3_t) + ", " + str(dht11_3_h) + ")"
        DB.execute(query)
        DB.commit()
                
    time.sleep(pause)

    ### DHT11_4
    dht11_4_h, dht11_4_t = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, DHT11_4)

    if dht11_4_h is not None and dht11_4_t is not None:
        query = "INSERT INTO dht11_4 (t, h) VALUES(" + str(dht11_4_t) + ", " + str(dht11_4_h) + ")"
        DB.execute(query)
        DB.commit()
                
    time.sleep(pause)

DB.close()
