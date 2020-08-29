# -*- coding: utf-8 -*-
import RPi.GPIO as GPIO
import Adafruit_DHT
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

sensor = Adafruit_DHT.DHT22

while True:
    time.sleep(1)
    dht22_h, dht22_t = Adafruit_DHT.read_retry(sensor, 14)

    if dht22_h is not None and dht22_t is not None:
        print ('t = ' + str(round(dht22_t, 1)))
        print ('h = ' + str(int(round(dht22_h))))

    time.sleep(5)
