# -*- coding: utf-8 -*-
import time
import sqlite3
import Adafruit_DHT

from config import config 

################### VARS ##########################################
dht22_1 = 24

dht11_1 = 24
dht11_2 = 24
dht11_3 = 24
dht11_4 = 24

# ds18b20 = 0
# rain = 0

# light1 = 0
# light2 = 0

pause = 10

################### INIT ##########################################
dht22_1_sensor = Adafruit_DHT.DHT22
dht11_1_sensor, dht11_2_sensor, dht11_3_sensor, dht11_4_sensor = Adafruit_DHT.DHT11

DB = sqlite3.connect(config.unoClimateDB)

while True:
    ################### DHT 22 #####################################
    ################### #1  ########################################
    h1, t1 = Adafruit_DHT.read_retry(dht22_1_sensor, dht22_1)

    if h1 is not None and t1 is not None:
        query = "INSERT INTO dht22_1 (t, h) VALUES(" + str(t1) + ", " + str(h1) + ")"
        DB.execute(query)
        DB.commit()

    time.sleep(pause)

    ################### DHT 11 #####################################
    ################### #1  ########################################
    h2, t2 = Adafruit_DHT.read_retry(dht11_1_sensor, dht11_1)

    if h2 is not None and t2 is not None:
        query = "INSERT INTO dht11_1 (t, h) VALUES(" + str(t2) + ", " + str(h2) + ")"
        DB.execute(query)
        DB.commit()

    time.sleep(pause)

    ################### #2  ########################################
    h3, t3 = Adafruit_DHT.read_retry(dht11_2_sensor, dht11_2)

    if h3 is not None and t3 is not None:
        query = "INSERT INTO dht11_2 (t, h) VALUES(" + str(t3) + ", " + str(h3) + ")"
        DB.execute(query)
        DB.commit()

    time.sleep(pause)

    ################### #3  ########################################
    h4, t4 = Adafruit_DHT.read_retry(dht11_3_sensor, dht11_3)

    if h4 is not None and t4 is not None:
        query = "INSERT INTO dht11_3 (t, h) VALUES(" + str(t4) + ", " + str(h4) + ")"
        DB.execute(query)
        DB.commit()

    time.sleep(pause)

    ################### #4  ########################################
    h5, t5 = Adafruit_DHT.read_retry(dht11_4_sensor, dht11_4)

    if h5 is not None and t5 is not None:
        query = "INSERT INTO dht11_4 (t, h) VALUES(" + str(t5) + ", " + str(h5) + ")"
        DB.execute(query)
        DB.commit()

    time.sleep(pause)

DB.close()
