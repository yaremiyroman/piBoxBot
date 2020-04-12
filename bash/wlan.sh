#!/bin/sh

while true; do
    clear

    printf " n143    => "
    iwconfig wlan0 | grep "Signal level"


    printf " TP-LINK => "
    iwconfig wlan1 | grep "Signal level"

    sleep 1
done
