# -*- coding: utf-8 -*-
import sqlite3
import serial

from config import config 

unoClimateSerial = serial.Serial(config.arduinoPort, 9600)

conn = sqlite3.connect(config.climate)

splitter = "||"

while True:
    if(unoClimateSerial.in_waiting > 0):
        sensors = unoClimateSerial.readline().decode().split(splitter)

        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if (len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                
                if (sensorName == 'dht11_1' or sensorName == 'dht11_2' or sensorName == 'dht11_3'):    
                    query = "INSERT INTO " + sensorName + " (t, h) VALUES(" + sensorParsed[1] + ", " + sensorParsed[2] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'moisture_1'):
                    query = "INSERT INTO " + sensorName + " (h) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
conn.close()
