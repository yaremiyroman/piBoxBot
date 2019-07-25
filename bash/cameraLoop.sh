#!/bin/sh

sleep 30

while true; do
  mkdir -p /home/pi/Pictures/cam/$(date +"%d_%m_%y")
  sleep 10
  file_path=/home/pi/Pictures/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg
  raspistill -q 80 -w 1440 -h 1080 -o $file_path
  sleep 600
done
