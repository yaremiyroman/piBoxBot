#!/bin/sh

echo '*** UPDATING EVERYTHING ************************************';

sudo apt -y update;
echo '✔️ UPDATED';

sudo apt -y upgrade;
echo '✔️ UPGRADED';

sudo apt -y dist-upgrade;
echo '✔️ DISTRO UPGRADED';

sudo apt -y autoremove;
echo '✔️ DEPENDENCIES CLEANED';

echo '✮✮✮ UPDATES: DONE ✮✮✮';
