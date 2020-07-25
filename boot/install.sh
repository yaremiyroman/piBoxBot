#!/bin/sh

echo '*** INSTALL: start';
cd;
pwd;
echo '';

echo '*** INSTALL: common *';
sudo apt -y install git mc zip unzip openconnect lynx sysbench foremost;

# echo '*** INSTALL: gpio and sensors ***';
#sudo apt -y install pi.gpio wiringpi lm-sensors;

echo '*** INSTALL: arduino ******';
sudo apt -y install arduino-core arduino-mk;

# echo '*** INSTALL: python *********';
#sudo apt -y install python python-is-python2 python-dev-is-python2 python-pip python-dev python3 python3-dev python3-pip sqlite3 libsqlite3-dev;

echo '*** INSTALL: node.js ************';
sudo apt -y install nodejs npm;

echo '*** INSTALL: yarn ***************';
cd ~;
curl -o- -L https://yarnpkg.com/install.sh | bash;

echo '*** INSTALL: finished';
echo '*********************';
git --version;
mc --version;
zip --version;
openconnect --version;
lynx --version;
sysbench --version;
echo 'node:';
node -v;
echo 'npm:';
npm -v;
echo 'yarn:';
yarn -v;

echo '✮✮✮ INSTALL: DONE ✮✮✮';
sleep 3;
