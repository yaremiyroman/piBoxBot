# -*- coding: utf-8 -*-
import serial
import sqlite3
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

conn = sqlite3.connect('/home/pi/piBoxBot/db/unoClimate.db')

mapSensorToTable = {
    't4': 'D4',
    'h4': 'D4',
    't5': 'D5',
    'h5': 'D5',
    't6': 'D6',
    'h6': 'D6',
    't7': 'D7',
    'h7': 'D7',
    't8': 'D8',
    'h8': 'D8'
}

mapValueToField = {
    't4': 'temperature',
    't5': 'temperature',
    't6': 'temperature',
    't7': 'temperature',
    't8': 'temperature',
    'h4': 'humidity',
    'h5': 'humidity',
    'h6': 'humidity',
    'h7': 'humidity',
    'h8': 'humidity'
}

while True:
    if(ser.in_waiting > 0):
        sensors = ser.readline().split(">>>")

        for sensorData in sensors:
            sensorParsed = sensorData.split("=")
            
            if(len(sensorParsed) > 1):
                sensorName = sensorParsed[0]
                sensorValue = sensorParsed[1]
                
                # print(sensorParsed)
                # print(sensorName)
                # print(sensorValue)
            
                query = "INSERT INTO " + sensorName + " (t) VALUES("+ sensorValue + ")"

                conn.execute(query)
                conn.commit()

conn.close()
