# -*- coding: utf-8 -*-
import sqlite3
import serial

from config import config 

conn = sqlite3.connect(config.climate)

unoClimateSerial = serial.Serial(config.unoClimatePort, 9600)

splitter = "||"

while True:
    if(unoClimateSerial.in_waiting > 0):
        sensors = unoClimateSerial.readline().decode().split(splitter)

        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if (len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                
                if (sensorName == 'ds18b20'):
                    query = "INSERT INTO " + sensorName + " (t) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'dht22_1' or sensorName == 'dht11_1' or sensorName == 'dht11_2' or sensorName == 'dht11_3' or sensorName == 'dht11_4'):    
                    query = "INSERT INTO " + sensorName + " (t, h) VALUES(" + sensorParsed[1] + ", " + sensorParsed[2] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'moi_1' or sensorName == 'moi_2'):
                    query = "INSERT INTO " + sensorName + " (h) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'liquid'):
                    query = "INSERT INTO " + sensorName + " (lvl) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'steam'):
                    query = "INSERT INTO " + sensorName + " (stm) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'rain'):
                    query = "INSERT INTO " + sensorName + " (rain) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                
                if (sensorName == 'light'):
                    query = "INSERT INTO " + sensorName + " (light) VALUES(" + sensorParsed[1] + ")"
                    conn.execute(query)
                    conn.commit()
                    
conn.close()
