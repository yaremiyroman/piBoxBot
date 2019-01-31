# -*- coding: utf-8 -*-
import serial

# ser = serial.Serial('/dev/ttyUSB0', 9600)
ser2 = serial.Serial('/dev/ttyACM0', 9600)

while True:
	print('===========================================')
	print('Serial_2')
	print(ser2.readline())
