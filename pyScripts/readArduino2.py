
import serial
from time import sleep

ser = serial.Serial(
    port='/dev/ttyAMA0',\
    baudrate=9600,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=1)

#/dev/tty.usbserial-AH02OC4V for mac, command line to find port: ls /dev/tty.*
#/dev/ttyUSB0 for Pi/Linux, command line to find port: ls /dev/tty*


value = 0
while True:
	ser.write("a")
	value = ord(ser.read())
	print "value: "
	print ser.read()
	sleep(.5)
