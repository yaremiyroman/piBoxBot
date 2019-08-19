# -*- coding: utf-8 -*-
# import os
# import math
from time import sleep
import Adafruit_DHT
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN)
GPIO.setup(14, GPIO.IN)
GPIO.setup(15, GPIO.IN)

DHT_SENSOR = Adafruit_DHT.DHT22
DHT_PIN = 24

while True:
    print("**** Read DHT22@BCM#24 ****** ")
    print("GPIO#24.input  > ")
    print(GPIO.input(24))
    print("DHT22@BCM#24  > ")
    humidity, temperature = Adafruit_DHT.read_retry(DHT_SENSOR, DHT_PIN)
    if humidity is not None and temperature is not None:
        # print("Temp={0:0.1f}'C  Humidity={1:0.1f}%".format(temperature, humidity))
        print("Temperature > ")
        print(temperature)
        print("Humidity > ")
        print(humidity)
    else:
        print("Failed to retrieve data from humidity sensor")
    sleep(15)
