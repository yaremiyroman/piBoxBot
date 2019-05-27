#!/bin/sh

sleep 30;

while true;
  do
    sleep 30;
    mkdir -p /home/pi/Pictures/usbCam/$(date +"%d_%m_%y")
    fswebcam -r 640x480 /home/pi/Pictures/usbCam/$(date +"%d_%m_%y")/usbCam_$(date +"%H_%M_%S").jpg
    sleep 60

    mkdir -p /home/pi/Pictures/cam/$(date +"%d_%m_%y")
    raspistill -q 40 -w 1440 -h 1080 -o /home/pi/Pictures/cam/$(date +"%d_%m_%y")/box_$(date +"%H_%M_%S").jpg;
    sleep 600;
done

# fswebcam should be apt-get-installed
# raspistill -t 1000 -w 640 -h 480 -q 33 --thumb none -ex auto -awb fluorescent -sh 75  -sa 10 -br 50 -o /home/pi/box_recent_photo.jpg;
# raspistill -t 1000 -w 640 -h 480 -o /home/pi/box_recent_photo.jpg;
# raspistill -t 1000 -ex auto -awb fluorescent -sh 75  -sa 10 -br 50 -o /home/pi/Pictures/cam/box_$(date +"%d_%m_%y__%H_%M_%S").jpg;
