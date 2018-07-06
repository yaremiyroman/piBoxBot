# piBoxBot

# how to run?

$ python3.6 bot.py
$ python3 bot.py

# cli font preferences

$ sudo dpkg-reconfigure console-setup

# update OS

$ sudo apt-get update
$ sudo apt-get dist-upgrade

# if you are not using PulseAudio for anything other than Bluetooth audio, remove it from the image by entering:

$ sudo apt-get -y purge "pulseaudio*"

# raspbian config

$ sudo raspi-config




# PASSWORDLESS SSH ACCESS
# https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md

# check if exist
$ ls ~/.ssh

# else
$ ssh-keygen
$ cat ~/.ssh/id_rsa.pub

# to copy your public key to your Raspberry Pi, use the following command to append the public key to your authorized_keys file on the Pi, sending it over SSH:

$ cat ~/.ssh/id_rsa.pub | ssh <USERNAME>@<IP-ADDRESS> 'mkdir -p ~/.ssh && cat >> ~/.ssh/authorized_keys'

# try ssh <USER>@<IP-ADDRESS> and you should connect without a password prompt.
# set an alias ib bash_profile

# if this did not work, delete your keys with rm ~/.ssh/id* and follow the instructions again.

# you can also send files over SSH using the scp command (secure copy). See the SCP guide for more information.

# STRESS
$ stress --cpu 4



# Check Raspberry Pi INFO

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

# Turns off video output.
$ vcgencmd display_power 0

$ cat /proc/version
$ cat /proc/meminfo
$ cat /proc/partitions
$ cat /proc/cpuinfo
$ cat /proc/cpuinfo
$ cat /proc/cpuinfo



$ vcgencmd get_mem arm && vcgencmd get_mem gpu


# If you're running a headless Raspberry Pi, there's no need to power the display circuitry, and you can save a little power by running /usr/bin/tvservice -o (-p to re-enable).
# Add the line to /etc/rc.local to disable HDMI on boot.

# Disable HDMI
/usr/bin/tvservice -o

# HDMI util and switching it off
$ tvservice
$ tvservice  --status
$ tvservice -o


# hostname and IP
$ hostname
$ hostname -I


# DISABLE THE BUILT-IN SOUND CARD OF RASPBERRY PI

$ cd /etc/modprobe.d
$ sudo nano alsa-blacklist.con
$ sudo reboot
$ aplay -l
# "...no soundcards found" indicates that kernel module (device driver) for broadcom chip was not loaded and the card has been disabled for all intents and purposes.


# SWITCH OFF NETWORK INTERFACES
$ ifconfig
$ crontab -e
# So that command runs at each boot.
$ @reboot sudo ifdown wlan0
# For stretch, you need to use
$ ip link set wlan0 down
# instead of ifdown
# or add it to /etc/rc.local with full bin name prefixed with e.g. /sbin/ip
# before exit 0

# !!!! Add to /boot/config.txt:

# Disable WiFi and Bluetooth
# wifi status
$ iwconfig
dtoverlay=pi3-disable-wifi
dtoverlay=pi3-disable-bt
# Check BT
$ hciconfig
