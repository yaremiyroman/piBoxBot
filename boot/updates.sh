#!/bin/sh

echo '*** UPDATES: start';

sudo apt -y update;
echo '*** UPDATES: UPDATED';

sudo apt -y upgrade;
echo '*** UPDATES: UPGRADED';

sudo apt -y dist-upgrade;
echo '*** UPDATES: DISTR UPGRADED';

sudo apt -y autoremove;
echo '*** UPDATES: DEPENDENCIES CLEANED';

echo '✮✮✮ UPDATES: done ✮✮✮';
