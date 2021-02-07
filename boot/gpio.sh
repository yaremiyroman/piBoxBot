#!/bin/sh

echo '*** INSTALL: gpio and sensors ***';
sudo apt -y install pi.gpio wiringpi lm-sensors;

echo '*** INSTALL: arduino ******';
sudo apt -y install arduino-core arduino-mk;

echo '*** INSTALL: python *********';
sudo apt -y install python python-is-python2 python-dev-is-python2 python-pip python-dev python3 python3-dev python3-pip sqlite3 libsqlite3-dev;

echo '✮✮✮ INSTALL: gpio packages installed ✮✮✮';
sleep 3;
