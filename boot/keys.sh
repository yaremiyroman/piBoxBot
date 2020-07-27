#!/bin/sh

echo '*** KEYS: ssh keys generator start';
echo '';

cd && pwd && mkdir ~/.ssh/;

echo 'KEYS: user@domain';
echo '';
whoami;
echo '@';
hostname;
echo '';
ssh-keygen -t rsa -b 4096 -P "" -C "$(whoami)@$(hostname)";
echo 'KEYS: generated';

eval "$(ssh-agent -s)";
ssh-add .ssh/id_rsa;
echo 'KEYS: added';
echo '';

echo 'KEYS: id_rsa.pub';
cat .ssh/id_rsa.pub;
echo '';
echo '✮✮✮ KEYS: DONE ✮✮✮';

echo '';
sleep 3
