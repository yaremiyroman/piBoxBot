#!/bin/sh

while true;
sleep 225;
do
rm /home/pi/box_recent_photo.jpg;
sleep 3;
# raspistill -t 1000 -w 640 -h 480 -q 33 --thumb none -ex auto -awb fluorescent -sh 75  -sa 10 -br 50 -o /home/pi/box_recent_photo.jpg;
raspistill -t 1000 -w 640 -h 480 -o /home/pi/box_recent_photo.jpg;
sleep 25;
# raspistill -t 1000 -ex auto -awb fluorescent -sh 75  -sa 10 -br 50 -o /home/pi/Pictures/cam/box_$(date +"%d_%m_%y__%H_%M_%S").jpg;
raspistill -t 1000 -o /home/pi/Pictures/cam/box_$(date +"%d_%m_%y__%H_%M_%S").jpg;
sleep 25;
done
