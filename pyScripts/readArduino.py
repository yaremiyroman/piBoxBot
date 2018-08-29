import sys
import serial

# make sure you write correct serial
arduino = serial.Serial("/dev/ttyUSB0")

arduino.baudrate=9600
temperature = arduino.readline()

print('********************************************')
print('------------Arduino sensors data------------')
print('Temperature [DS18b20]: {}'.format(temperature))
print('********************************************')
