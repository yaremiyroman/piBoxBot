#!/bin/sh

echo '*** INSTALL.SH *********************************************';
cd;
pwd;
echo '';

echo '*** UPDATING EVERYTHING ************************************';
sudo apt -y update;
echo '✔️ UPDATED';
echo '';
sudo apt -y upgrade;
echo '✔️ UPGRADED';
echo '';
sudo apt -y dist-upgrade;
echo '✔️ DISTRO UPGRADED';
echo '';
sudo apt -y autoremove;
echo '✔️ DEPENDENCIES CLEANED';
echo '';
echo '✮✮✮ UPDATES: DONE ✮✮✮';
echo '';

echo '*** SOFTWARE INSTALLATION **********************************';
echo '*** INSTALLING ***';
sudo apt -y install git mc zip unzip openconnect lynx sysbench;
echo '*** INSTALLING ******';
sudo apt -y install pi.gpio wiringpi lm-sensors;
echo '*** INSTALLING *********';
sudo apt -y install arduino-core arduino-mk;
echo '*** INSTALLING ************';
sudo apt -y install python python-is-python2 python-dev-is-python2 python-pip python-dev python3 python3-dev python3-pip sqlite3 libsqlite3-dev;
echo '*** INSTALLING ***************';
sudo apt -y install nodejs npm;
echo '*** INSTALLING ******************';
curl -o- -L https://yarnpkg.com/install.sh | bash;
echo '✔️ INSTALLED: ;
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
echo '✮✮✮ SOFTWARE READY ✮✮✮';

echo '***********************************************************';
sleep 3;
echo '***********************************************************';
