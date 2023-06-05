# -*- coding: utf-8 -*-
import sqlite3
import serial
from config import config 

climateSerial = serial.Serial(config.climatePort, 9600)

while True:
    if(climateSerial.in_waiting > 0):
        sensors = climateSerial.readline().decode().split(config.splitter)
        climateDB = sqlite3.connect(config.climateDB)
        
        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if (len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                
                if (sensorName == 'dht22.a' or sensorName == 'dht2' or sensorName == 'dht3' or sensorName == 'dht4'):    
                    query = "INSERT INTO " + sensorName + " (t, h) VALUES(" + sensorParsed[1] + ", " + sensorParsed[2] + ")"
                    climateDB.execute(query)
                    climateDB.commit()
                
        climateDB.close()
