# -*- coding: utf-8 -*-
import time
import sqlite3
import Adafruit_DHT

import config

DHT_22_1 = Adafruit_DHT.DHT22
DHT_22_1_PIN = 24

DB = sqlite3.connect(config.unoClimateDB)

while True:
    h1, t1 = Adafruit_DHT.read_retry(DHT_22_1, DHT_22_1_PIN)

    if h1 is not None and t1 is not None:
        query = "INSERT INTO dht22_1 (t, h) VALUES(" + str(t1) + ", " + str(h1) + ")"
        DB.execute(query)
        DB.commit()
    
    time.sleep(10)
                
DB.close()
