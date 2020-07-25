#!/bin/sh

echo '*** ALIASES: importing';

cd /boot/
cp aliases ~/.bash_aliases;

echo '*** ALIASES: re-login to make them work';
echo '✮✮✮ ALIASES: DONE ✮✮✮';
sleep 3;
