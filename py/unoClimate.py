# -*- coding: utf-8 -*-
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
    if(ser.in_waiting > 0):
        line = ser.readline()
        # print(line.decode())
        print(line)
