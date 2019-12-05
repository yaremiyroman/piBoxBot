#!/bin/sh

apt-get -y update;
apt-get -y upgrade;
apt-get -y dist-upgrade;
apt-get -y autoremove;

apt-get -y install git mc;
apt-get -y install rpi.gpio wiringpi;
apt-get -y install bc lm-sensors;
apt-get -y install python python-dev python-pip python3 python3-dev python3-pip sqlite3 libsqlite3-dev;
apt-get -y install arduino-core arduino-mk;

pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT;

sleep 3;

reboot;
