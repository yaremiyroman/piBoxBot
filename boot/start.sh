#!/bin/sh

echo '*** PI: setup start';

sudo raspi-config;
./keys.sh;
./aliases.sh;
./updates.sh;
./install.sh;
./git.sh;

echo '*** PI: setup done';
