#!/bin/sh

git config --global user.email "yaremiyroman@gmail.com" &&
git config --global user.name "andrdrx@piMedia" &&
cd ~ && git clone git@github.com:yaremiyroman/piBoxBot.git && cd piBoxBot && git checkout dev && cd ~; 
