#!/bin/sh

sudo apt-get -y update;
sudo apt-get -y upgrade;
sudo apt-get -y dist-upgrade;
sudo apt-get -y autoremove;

sudo apt-get -y install git mc && sudo apt-get -y install rpi.gpio wiringpi && sudo apt-get -y install bc lm-sensors && sudo apt-get -y install python python-dev python-pip python3 python3-dev python3-pip sqlite3 libsqlite3-dev && pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT
# sudo apt-get -y install arduino-core arduino-mk;


sleep 3;

reboot;
