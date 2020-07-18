#!/bin/sh

echo '*** SSH SETTING UP **********************************';
echo '';

cd && pwd && mkdir ~/.ssh/;
echo '$(whoami)@$(hostname)';
ssh-keygen -t rsa -b 4096 -P "" -C "$(whoami)@$(hostname)";
eval "$(ssh-agent -s)";

ssh-add .ssh/id_rsa;
echo '✔️ SSH KEYS GENERATED';
echo '';

echo '✮✮✮ id_rsa.pub ✮✮✮';
cat .ssh/id_rsa.pub;
echo '';
echo '✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮✮';
echo '';
sleep 3
