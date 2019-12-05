#!/bin/sh


apt-get -y install git;

git config --global user.email "yaremiyroman@gmail.com";

git config --global user.name "andrdrx@piMedia";

cd /home/pi/;

git clone git@github.com:yaremiyroman/piBoxBot.git;

cd piBoxBot ;

git checkout dev;

cd ~;
