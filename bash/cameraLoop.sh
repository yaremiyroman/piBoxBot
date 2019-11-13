#!/bin/sh

sleep 30

while true; do
  mkdir -p /home/pi/cam/$(date +"%d_%m_%y")
  file_path=/home/pi/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg

  raspistill   -q 80   -w 1920   -h 1080      --awb horizon     -o $file_path    -n

  cp $file_path /home/pi/cam_telebot.jpg
  
  sleep 60
done
