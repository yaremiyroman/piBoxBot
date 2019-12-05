# pi setup
# Download balenaEtcher app and flash microSD with Raspbian image
# Write an empty text file named "ssh" (no file extension) to the root of the directory of the card. When it sees the "ssh" on its first boot-up, Raspbian will automatically enable SSH
# Wi-Fi: create a text file called wpa_supplicant.conf near "ssh", Find piBoxBot/configs/wpa_supplicant.conf for example.ss

# ########################################################### #
# configs
# ########################################################### #
$ sudo raspi-config
$ sudo nano /etc/default/locale
$ sudo nano ~/.bashrc
$ sudo nano /etc/rc.local
$ sudo nano /boot/config.txt
$ sudo nano /lib/udev/hwclock-set
$ crontab -e

# ########################################################### #
# SSH
# ########################################################### #
$ ssh-keygen -t rsa -b 4096 -C "yaremiyroman@gmail.com"
$ eval "$(ssh-agent -s)"
$ ssh-add ~/.ssh/id_rsa
$ cat ~/.ssh/id_rsa.pub
$ cat /home/pi/.ssh/id_rsa.pub | ssh pi@192.168.31.187 'cat >> /home/pi/.ssh/authorized_keys'

# ########################################################### #
# git
# ########################################################### #
$ git config --global user.email "yaremiyroman@gmail.com" && git config --global user.name "andrdrx@piMedia" &&  git clone git@github.com:yaremiyroman/piBoxBot.git && cd piBoxBot && git checkout dev

# ########################################################### #
# install
# ########################################################### #
$ sudo apt-get install git mc
$ sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade && sudo apt-get autoremove
$ sudo apt-get install rpi.gpio wiringpi
$ sudo apt-get install bc lm-sensors
$ sudo apt-get install python python-dev python-pip python3 python3-dev python3-pip sqlite3 libsqlite3-dev
$ pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT
$ sudo apt-get install arduino-core arduino-mk

# ########################################################### #
# info
# ########################################################### #
$ vcgencmd commands
$ stress --cpu 4
$ sudo echo "$(cat /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon1/temp1_input)/1000" | bc -l
$ sensors
