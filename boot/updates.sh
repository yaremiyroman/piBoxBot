#!/bin/sh

echo '*** UPDATES: start';

sudo apt -y update;
echo '*** UPDATES: UPDATED';

sudo apt -y full-upgrade;
echo '*** UPDATES: UPGRADED';

sudo apt -y autoremove;
echo '*** UPDATES: DEPENDENCIES CLEANED';

sudo apt -y clean;
echo '*** UPDATES: /var/cache/apt/archives CLEANED';

echo '✮✮✮ UPDATES: done ✮✮✮';
