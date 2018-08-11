# piBoxBot

# IMPORTANT SYSTEM FILES
/boot/config.txt

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







# CAMERA
$ raspistill -o cam.jpg
# VERTICAL FLIP & HORIZONTAL FLIP
$ raspistill -vf -hf -o cam2.jpg
Raspberry Pi camera module commands
To see a list of possible options for running raspivid or raspistill, you can run:
#raspivid | less
# raspistill | less
# Use the arrow keys to scroll and type q to exit.
# Still captures
# By default, captures are done at the highest resolution supported by the sensor. This can be changed using the -w and -h command line options.
# Capture an image in jpeg format:
# raspistill -o image.jpg
# Taking a default capture after 2s (note times are specified in milliseconds) on viewfinder, saving in image.jpg
# raspistill -t 2000 -o image.jpg
# Take a capture at a different resolution.
# raspistill -t 2000 -o image.jpg -w 640 -h 480
# Now reduce the quality considerably to reduce file size
# raspistill -t 2000 -o image.jpg -q 5
# Force the preview to appear at coordinate 100,100, with width 300 and height 200 pixels.
# raspistill -t 2000 -o image.jpg -p 100,100,300,200
# Disable preview entirely
# raspistill -t 2000 -o image.jpg -n
# Save the image as a png file (lossless compression, but slower than JPEG). Note that the filename suffix is ignored when choosing the image encoding.
# raspistill -t 2000 -o image.png –e png
# Add some EXIF information to the JPEG. This sets the Artist tag name to Boris, and the GPS altitude to 123.5m. Note that if setting GPS tags you should set as a minimum GPSLatitude, GPSLatitudeRef, GPSLongitude, GPSLongitudeRef, GPSAltitude and GPSAltitudeRef.
# raspistill -t 2000 -o image.jpg -x IFDO.Artist=Boris -x GPS.GPSAltitude=1235/10
# Set an emboss style image effect
# raspistill -t 2000 -o image.jpg -ifx emboss
# Set the U and V channels of the YUV image to specific values (128:128 produces a greyscale image)
# raspistill -t 2000 -o image.jpg -cfx 128:128
# Run preview ONLY for 2s, no saved image.
# raspistill -t 2000
# Take timelapse picture, one every 10 seconds for 10 minutes (10 minutes = 600000ms), named image_num_001_today.jpg, image_num_002_today.jpg onwards, with the latest picture also available under the name latest.jpg.
# raspistill -t 600000 -tl 10000 -o image_num_%03d_today.jpg -l latest.jpg
# Take a picture and send image data to stdout
# raspistill -t 2000 -o –
# Take a picture and send image data to file
# raspistill -t 2000 -o – > my_file.jpg
# Run camera forever, taking a picture when Enter is pressed
# raspistill -t 0 -k -o my_pics%02d.jpg
# Video Captures
# Image size and preview settings are the same as for stills capture. Default size for video recording is 1080p (1920×1080)
# Record a 5s clip with default settings (1080p30)
# raspivid -t 5000 -o video.h264
# Record a 5s clip at a specified bitrate (3.5MBits/s)
# raspivid -t 5000 -o video.h264 -b 3500000
# Record a 5s clip at a specified framerate (5fps)
# raspivid -t 5000 -o video.h264 -f 5
# Encode a 5s camera stream and send image data to stdout
# raspivid -t 5000 -o –
# Encode a 5s camera stream and send image data to file
# raspivid -t 5000 -o – > my_file.h264






# TELEBOT

$ pip3 install pytelegrambotapi





# DHT 22

$ sudo apt-get update
$ sudo apt-get install build-essential python-dev python-openssl
$ git clone https://github.com/adafruit/Adafruit_Python_DHT.git
# rename it
$ cd dht
$ sudo python setup.py install
$ cd examples
$ sudo ./AdafruitDHT.py 2302 4
$ sudo ./AdafruitDHT.py 22 P8_11

# do something with interval
$ watch <SOME_COMMAND>


# RTC DS3231
#enable i2c
# add to /boot/config.txt
dtoverlay=i2c-rtc,ds3231
# comment in /lib/udev/hwclock-set with sharp-symbol
if [ -e /run/systemd/system ] ; then
exit 0
fi

$ sudo reboot
# and test
$ sudo hwclock -r

$ sudo pip3 install telegram-send
$ pip3 install telegram-send
$
