#!/bin/sh

sleep 10

while true; do
  mkdir -p /home/pi/cam/$(date +"%d_%m_%y")
  file_path=/home/pi/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg

  raspistill   -q 80   -w 1920   -h 1080      --awb horizon     -o $file_path    -n

  cp $file_path /home/pi/cam_telebot.jpg

  scp $file_path pi@192.168.31.187:/home/pi/cam.jpg

  sleep 900
done
