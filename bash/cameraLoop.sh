#!/bin/sh

sleep 30

while true; do
  mkdir -p /home/pi/Pictures/cam/$(date +"%d_%m_%y")
  sleep 10
  raspistill -q 40 -w 1440 -h 1080 -o /home/pi/Pictures/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg
  sleep 300
  raspistill -q 85 -sh 15 -ISO 400 -ex auto -w 2592 -h 1944 -o /home/pi/Pictures/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg
  sleep 300
done
