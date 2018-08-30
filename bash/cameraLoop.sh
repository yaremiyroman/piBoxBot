#!/bin/bash

sleep 60;

while true;
do raspistill -o /home/pi/Pictures/cam/box_$(date +"%d_%m_%y__%H_%M_%S").jpg;
sleep 300;
done
