# -*- coding: utf-8 -*-

# Import the libraries to use time delays, send os commands and access GPIO pins
import RPi.GPIO as GPIO
from time import sleep
import os

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(21, GPIO.IN)

print('!!! INITIAL GPIO control input(21) > ')
print(GPIO.input(21))

while True:
    if GPIO.input(21) == 1:
        print('System shuts down')
        os.system('sudo shutdown -h now')
        time.sleep(1)
