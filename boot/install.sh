#!/bin/sh

echo '*** INSTALL: start';
cd;
pwd;
echo '';

./install/common.sh;
./install/gpio.sh;
./install/node.sh;

echo '*** INSTALL: finished ************************';
echo '';

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

echo '✮✮✮ INSTALL: DONE ✮✮✮';
sleep 3;
