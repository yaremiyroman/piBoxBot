# pi setup ###########################################################################
# Download balenaEtcher app and flash microSD with Raspbian image
# Write an empty text file named "ssh" (no file extension) to the root of the directory of the card. When it sees the "ssh" on its first boot-up, Raspbian will automatically enable SSH
# Wi-Fi: create a text file called wpa_supplicant.conf near "ssh", Find piBoxBot/configs/wpa_supplicant.conf for example.ss
$ sudo raspi-conf
$ sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade && sudo apt-get autoremove && sudo apt-get autoclean
$ sudo apt-get install build-essential git git-core mc rpi.gpio wiringpi bc lm-sensors arduino arduino-mk python python-is-dev python-pip python3 python3-is-dev python3-pip sqlite3 libsqlite3-dev luvcview

###########################################
# configs
###########################################
$ sudo nano ~/.bashrc
$ sudo nano /etc/rc.local
$ sudo nano /boot/config.txt
$ crontab -e

###########################################
# SSH
###########################################
$ ssh-keygen -t rsa -b 4096 -C "yaremiyroman@gmail.com"
$ eval "$(ssh-agent -s)"
$ ssh-add ~/.ssh/id_rsa
$ cat ~/.ssh/id_rsa.pub
$ cat /Users/rx/.ssh/id_rsa.pub | ssh pi@piData.local 'cat >> /home/pi/.ssh/authorized_keys'

###########################################
# git
###########################################
$ git config --global user.email "yaremiyroman@gmail.com" && git config --global user.name "andrdrx@piTest"
$ git@github.com:yaremiyroman/piBoxBot.git

###########################################
# info
###########################################
$ vcgencmd commands
$ stress --cpu 4

###########################################
# telebot
###########################################
$ pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT

###########################################
# RTC
###########################################
# /boot/config.txt
dtoverlay=i2c-rtc,ds3231
# /lib/udev/hwclock-set comment
if [ -e /run/systemd/system ] ; then
   exit 0
fi
$ hwclock -r, -w
$ sudo echo "$(cat /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon1/temp1_input)/1000" | bc -l

##############################################################################
# luvcview: camera preview
##############################################################################
$ sudo apt-get install luvcview
$ luvcview

##############################################################################
# bot.service
##############################################################################
Description=Running Telebot
After=network.target

[Service]
ExecStart=/usr/bin/python -u bot.py
WorkingDirectory=/home/pi/piBoxBot/py
StandardOutput=inherit
StandardError=inherit
Restart=always
User=pi

[Install]
WantedBy=multi-user.target
