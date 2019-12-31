#!/bin/sh

sleep 10

zip -r /home/pi/archive/$(date +"%d_%m_%y").zip /home/pi/cam/$(date +"%d_%m_%y")/*
