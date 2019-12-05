#!/bin/sh

# pi setup

#https://github.com/RPi-Distro/raspi-config/blob/master/raspi-config#L542

# ########################################################### #
# SETTINGS
# ########################################################### #
#user_mail=yaremiyroman@gmail.com

# ########################################################### #
# PASSWORD
# ########################################################### #
# passwd;
# sleep 3;

# ########################################################### #
# HOSTNAME
# ########################################################### #
# CURRENT_HOSTNAME=`cat /etc/hostname | tr -d " \t\n\r"`;
# NEW_HOSTNAME=$(whiptail --inputbox "Please enter a hostname" 10 40 ${CURRENT_HOSTNAME}  3>&1 1>&2 2>&3);
# echo $NEW_HOSTNAME > /etc/hostname;
# sed -i "s/127.0.1.1.*$CURRENT_HOSTNAME/127.0.1.1\t$NEW_HOSTNAME/g" /etc/hosts;
# sleep 3;

# ########################################################### #
# LOCALE
# ########################################################### #
# perl -pi -e 's/# en_GB.UTF-8 UTF-8/en_GB.UTF-8 UTF-8/g' /etc/locale.gen;
# sleep 1;
# locale-gen;
# sleep 1;
# update-locale;
# sleep 3;

# ########################################################### #
# INSTALL
# ########################################################### #
sudo apt-get update &&
sudo apt-get upgrade &&
sudo apt-get dist-upgrade &&
sudo apt-get autoremove &&
sudo apt-get install git mc &&
sudo apt-get install rpi.gpio wiringpi &&
sudo apt-get install bc lm-sensors &&
sudo apt-get install python python-dev python-pip python3 python3-dev python3-pip sqlite3 libsqlite3-dev &&
sudo apt-get install arduino-core arduino-mk &&
pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT;
sleep 3;

# ########################################################### #
# SSH
# ########################################################### #
# ssh-keygen -t rsa -b 4096 -C "yaremiyroman@gmail.com"
# eval "$(ssh-agent -s)"
# ssh-add ~/.ssh/id_rsa
# cat ~/.ssh/id_rsa.pub

# ########################################################### #
# git
# ########################################################### #
# git config --global user.email "yaremiyroman@gmail.com"
# git config --global user.name "andrdrx@piMedia"
# cd /home/pi/
# git clone git@github.com:yaremiyroman/piBoxBot.git
# cd piBoxBot 
# git checkout dev


# $ sudo nano ~/.bashrc

# $ sudo nano /etc/rc.local

# $ sudo nano /boot/config.txt

# $ sudo nano /lib/udev/hwclock-set

# $ crontab -e
