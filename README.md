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




# Check Raspberry Pi temperature from SSH (CLI)

$ cat /opt/vc/bin/vcgencmd measure_temp
$ cat /sys/class/thermal/thermal_zone0/temp
$ watch /opt/vc/bin/vcgencmd measure_temp
$ vcgencmd measure_temp

# INFO

$ cat /proc/version
$ cat /proc/meminfo
$ cat /proc/partitions
$ cat /proc/cpuinfo
$ cat /proc/cpuinfo
$ cat /proc/cpuinfo



$ vcgencmd get_mem arm && vcgencmd get_mem gpu
