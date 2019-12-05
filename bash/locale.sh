#!/bin/sh

perl -pi -e 's/# en_GB.UTF-8 UTF-8/en_GB.UTF-8 UTF-8/g' /etc/locale.gen;

sleep 1;

locale-gen;

sleep 1;

update-locale;

sleep 5;

reboot;
