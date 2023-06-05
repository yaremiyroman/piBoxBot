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
                query = "INSERT INTO dht22_1 (t, h) VALUES(" + sensorParsed[0] + ", " + sensorParsed[1] + ")"
                climateDB.execute(query)
                climateDB.commit()
                
                
        climateDB.close()
