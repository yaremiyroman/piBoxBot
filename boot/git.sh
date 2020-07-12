#!/bin/sh

echo '*** GIT GLOBAL CONFIG ************************************';

git config --global user.email "yaremiyroman@gmail.com";
echo '✔️ email';
echo 'yaremiyroman@gmail.com';
echo '';

git config --global user.name "$(whoami)@$(hostname)";
echo '✔️ userName';
echo '$(whoami)@$(hostname)';
echo '';

cd && git clone git@github.com:yaremiyroman/piBoxBot.git;
echo '✮✮✮ piBoxBot pulled ✮✮✮';

cd piBoxBot && git checkout dev;
echo '✮✮✮ piBoxBot@dev ✮✮✮';
cd;
pwd;
echo '';
