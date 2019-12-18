#!/bin/sh

ssh-keygen -t rsa -b 4096 -P "" -C "yaremiyroman@gmail.com" &&
eval "$(ssh-agent -s)" &&
ssh-add ~/.ssh/id_rsa &&
cat ~/.ssh/id_rsa.pub &&
sleep 3;
