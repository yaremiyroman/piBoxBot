# -*- coding: utf-8 -*-
import sqlite3
import serial

import config

unoClimateSerial = serial.Serial(config.unoClimate, 9600)

conn = sqlite3.connect(config.unoClimateDB)

while True:
    if(unoClimateSerial.in_waiting > 0):
        sensors = unoClimateSerial.readline().decode().split(">>>")

        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if (len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                
                if (sensorName == 'ds18b20'):    
                    query = "INSERT INTO " + sensorName + " (t) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'dht11_1' or sensorName == 'dht11_2' or sensorName == 'dht11_3' or sensorName == 'dht11_4' or sensorName == 'dht22_1'):    
                    query = "INSERT INTO " + sensorName + " (t, h) VALUES(" + sensorParsed[1] + ", " + sensorParsed[2] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'mousture_1' or sensorName == 'mousture_2' or sensorName == 'mousture_3' or sensorName == 'mousture_4' or sensorName == 'steam_1'):    
                    query = "INSERT INTO " + sensorName + " (h) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'light_1'):    
                    query = "INSERT INTO " + sensorName + " (l) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()

conn.close()
