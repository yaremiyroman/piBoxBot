#!/bin/sh

cd ~;
echo '***********************************************************';
pwd;
echo '***********************************************************';

echo '*** UPDATING **********************************************';
sudo apt-get -y update;
sudo apt-get -y upgrade;
sudo apt-get -y dist-upgrade;
sudo apt-get -y autoremove;

echo '*** INSTALLING ********************************************';
sudo apt-get -y install git mc zip unzip openconnect lynx sysbench;
sudo apt-get -y install pi.gpio wiringpi lm-sensors;
sudo apt-get -y install arduino-core arduino-mk;
sudo apt-get -y install python python-is-python2 python-dev-is-python2  python3 python3-dev python3-pip sqlite3 libsqlite3-dev;
sudo apt-get -y install nodejs npm;
# curl -o- -L https://yarnpkg.com/install.sh | bash;

echo '*** DONE **************************************************';
node -v;
npm -v;
# yarn -v;

echo '***********************************************************';
cd;
pwd;
echo '***********************************************************';
sleep 3;
