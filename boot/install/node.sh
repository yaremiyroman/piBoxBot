#!/bin/sh

echo '*** INSTALL: node.js ************';
sudo apt -y install nodejs npm;

echo '*** INSTALL: yarn ***************';
cd ~;
pwd;
curl -o- -L https://yarnpkg.com/install.sh | bash;

echo '✮✮✮ INSTALL: node environment installed ✮✮✮';
sleep 3;
