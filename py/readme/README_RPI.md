######################################################################################
# Pi setup
######################################################################################
# Download Raspbian release
# Download balenaEtcher app and flash microSD with Raspbian image
# Write an empty text file named "ssh" (no file extension) to the root of the directory of the card. When it sees the "ssh" on its first boot-up, Raspbian will automatically enable SSH
# Wi-Fi: create a text file called wpa_supplicant.conf near "ssh", Find piBoxBot/configs/wpa_supplicant.conf for example.

###########################################
# SSH
# https://help.github.com/en/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent
###########################################
$ ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
# Adding your SSH key to the ssh-agent
$ eval "$(ssh-agent -s)"
### -----------------------------------------
# If you're using macOS Sierra 10.12.2 or later, you will need to modify 
# your ~/.ssh/config file to automatically load keys into the ssh-agent 
# and store passphrases in your keychain.
Host *
  AddKeysToAgent yes
  UseKeychain yes
  IdentityFile ~/.ssh/id_rsa
# -------
$ ssh-add -K ~/.ssh/id_rsa
### -----------------------------------------
# Copy fresh Pi key to GitHub -> Preferences -> SSH keys
$ cat ~/.ssh/id_rsa.pub
# Copy Host's public key to Pi over SSH: authorize the key on Pi
$ cat ~/.ssh/id_rsa.pub | ssh <USERNAME>@<IP-ADDRESS> 'mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys'
$ cat /Users/rx/.ssh/id_rsa.pub | ssh pi@piMedia.local 'cat >> /home/pi/.ssh/authorized_keys'
# Connect:
$ ssh <USER>@<IP-ADDRESS>
# If SSH fails:
$ rm ~/.ssh/id*
$ <GOTO: BEGIN>

###########################################
# GIT configs
###########################################
$ git config --global user.email "yaremiyroman@gmail.com"
$ git config --global user.name "andrdrx@piData"

###########################################
# Add an alias
###########################################
$ sudo nano ~/.bashrc
# Alias format: alias <ALIAS_NAME>='<INSTRUCTIONS>'
# Find piBoxBot/configs/bashrc for example

###########################################
# SCP
###########################################
$ scp  /home/<USER>/<SOME_FOLDER>/<IMAGE_SAMPLE>.jpg   <USER>@<IP-ADDRESS>:/home/pi/<SOME_FOLDER>/

###########################################
# Update OS and packages
###########################################
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade
$ sudo apt autoremove
# bundle
$ sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade && sudo apt-get autoremove

###########################################
# Set locale if terminal shows warnings about
###########################################
$ sudo nano /etc/default/locale
# add any that missed
LANG=en_US.UTF-8
LC_ALL=en_US.UTF-8
LC_CTYPE="en_US.UTF-8"
LC_ALL="en_US.UTF-8"
LANG="en_US.UTF-8"

###########################################
# Get Pi info
###########################################
$ cat /opt/vc/bin/vcgencmd measure_temp
$ cat /sys/class/thermal/thermal_zone0/temp
$ watch /opt/vc/bin/vcgencmd measure_temp
$ vcgencmd commands
$ vcgencmd get_config int
$ vcgencmd measure_temp
$ vcgencmd measure_clock arm
$ vcgencmd measure_volts core
# sh .get_temperature.sh
# temp = 49.8°C (121.64°F)
$ vcgencmd get_mem arm && vcgencmd get_mem gpu
$ cat /proc/version
$ cat /proc/meminfo
$ cat /proc/partitions
$ cat /proc/cpuinfo
$ vcgencmd get_mem arm && vcgencmd get_mem gpu

###########################################
# Stress the CPU
###########################################
$ stress --cpu 4

###########################################
# Reduce the amount of current consumed by Pi
###########################################

# HDMI ####################################
# Check HDMI
$ tvservice -s
# Disable HDMI 
$ tvservice -o
# Enable HDMI
$ tvservice -p
# Disable HDMI on cron
$ crontab -e
# Add a cron rule
$ @reboot tvservice -o
$ sudo reboot

# WLAN and BT
# Get list if network interfaces
$ iwconfig
# Add rules
$ sudo nano /boot/config.txt
# $ dtoverlay=pi3-disable-wifi
# $ dtoverlay=pi3-disable-bt
$ sudo reboot
# Check interfaces
$ hciconfig
$ iwconfig

# Audio
$ sudo nano /boot/config.txt
# $ dtparam=audio=off

###########################################
# CAMERA: piBoxBot/py/readme/RaspiCam.pdf
###########################################

###########################################
# RTC(DS3231) setup
###########################################

# enable i2c
$ sudo nano /boot/config.txt
# add
dtoverlay=i2c-rtc,ds3231
# in hwclock config
$ sudo nano /lib/udev/hwclock-set
# comment 
if [ -e /run/systemd/system ] ; then
   exit 0
fi
# then
$ sudo reboot
# register RTC and sync system time on startup 
$ sudo nano /etc/rc.local
# add before "exit 0"
echo ds3231 0x68 > /sys/class/i2c-adapter/i2c-1/new_device
hwclock -s
$ sudo reboot

# hwclock: read, write
$ hwclock -r, -w


# Read sensors and various RTC data
$ sudo apt-get install lm-sensors
$ sensors

# Read RTC temperature
$ sudo apt-get install bc
$ sudo echo "$(cat /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon1/temp1_input)/1000" | bc -l


###########################################
# telebot
###########################################

$ pip3 install pytelegrambotapi
$ pip3 install telegram-send
# AttributeError: 'TeleBot' object has no attribute
$ pip3 uninstall telebot PyTelegramBotAPI
$ pip3 install PyTelegramBotAPI==2.2.3
# and it works now!
