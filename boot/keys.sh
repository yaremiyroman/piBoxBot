#!/bin/sh

cd;
mkdir ~/.ssh/;

ssh-keygen -t rsa -b 4096 -P "" -C "andrdrx@$(hostname)";
eval "$(ssh-agent -s)";

ssh-add .ssh/id_rsa;
cat .ssh/id_rsa.pub;

sleep 5
