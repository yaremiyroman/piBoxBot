# -*- coding: utf-8 -*-
from time import sleep
import Adafruit_DHT
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

dht22 = Adafruit_DHT.DHT22
pin = 24

GPIO.setup(pin, GPIO.IN)

while True:
    humidity, temperature = Adafruit_DHT.read_retry(dht22, pin)
    
    if humidity is not None and temperature is not None:
        print(temperature)
        print(humidity)
    else:
        print("Failed to retrieve data from humidity sensor")
        
    sleep(60)
