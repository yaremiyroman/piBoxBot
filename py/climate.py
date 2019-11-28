# -*- coding: utf-8 -*-
import sqlite3
import serial
from config import config 

unoClimateSerial = serial.Serial(config.climateDBPort, 9600)

while True:
    if(unoClimateSerial.in_waiting > 0):
        sensors = unoClimateSerial.readline().decode().split(config.splitter)
        climateDB = sqlite3.connect(config.climateDB)
        
        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if (len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                
                if (sensorName == 'ds18b20'):
                    query = "INSERT INTO " + sensorName + " (t) VALUES(" + sensorParsed[1] + ")"
                    climateDB.execute(query)
                    climateDB.commit()
                
                if (sensorName == 'dht_1' or sensorName == 'dht_2' or sensorName == 'dht_3' or sensorName == 'dht_4'):    
                    query = "INSERT INTO " + sensorName + " (t, h) VALUES(" + sensorParsed[1] + ", " + sensorParsed[2] + ")"
                    climateDB.execute(query)
                    climateDB.commit()
                
                # if (sensorName == 'lm35'):
                #     query = "INSERT INTO " + sensorName + " (h) VALUES(" + sensorParsed[1] + ")"
                #     climateDB.execute(query)
                #     climateDB.commit()
                
                
                # if (sensorName == 'moi'):
                #     query = "INSERT INTO " + sensorName + " (h) VALUES(" + sensorParsed[1] + ")"
                #     climateDB.execute(query)
                #     climateDB.commit()
                
                # if (sensorName == 'steam'):
                #     query = "INSERT INTO " + sensorName + " (stm) VALUES(" + sensorParsed[1] + ")"
                #     climateDB.execute(query)
                #     climateDB.commit()
                
                # if (sensorName == 'light'):
                #     query = "INSERT INTO " + sensorName + " (light) VALUES(" + sensorParsed[1] + ")"
                #     climateDB.execute(query)
                #     climateDB.commit()
                    
        climateDB.close()
