#!/bin/sh

$home='/home/pi'

mkdir $home.ssh/;

ssh-keygen -t rsa -b 4096 -P ""
	-C "yaremiyroman@gmail.com";

eval "$(ssh-agent -s)";

cd && ssh-add .ssh/id_rsa;

cat .ssh/id_rsa.pub;
sleep 3
