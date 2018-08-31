#!/bin/sh

while true;
sleep 225;
rm /home/pi/box_recent_photo.jpg;
sleep 3;
do raspistill -t 50 -w 640 -h 480 -q 33 --thumb none --exif none -o /home/pi/box_recent_photo.jpg
sleep 25;
do raspistill -t 100 -o /home/pi/Pictures/cam/box_$(date +"%d_%m_%y__%H_%M_%S").jpg;
sleep 25;
done
