# Raspberry PI section

# IMPORTANT SYSTEM FILES
/boot/config.txt

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



$ vcgencmd get_mem arm && vcgencmd get_mem gpu

# If you're running a headless Raspberry Pi, there's no need to power the display circuitry, and you can save a little power by running /usr/bin/tvservice -o (-p to re-enable).

# TURN OFF HDME add to crontab
$ tvservice -o       
# CHECK HDMI STATUS       
$ tvservice  --status

# hostname and IP
$ hostname
$ hostname -I

# SWITCH OFF NETWORK INTERFACES
# POWER OFF WLAN
$ sudo crontab -e
$ @reboot ifconfig eth0 down

# Disable WiFi and Bluetooth
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

# DHT 22
# RTFM!!!!
# https://github.com/adafruit/Adafruit_Python_DHT
# RTFM!!!!

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

# Подключение RTC (часы реального времени) к Raspberry Pi
# АВТОР RASPIMAN  24 ЯНВАРЬ 2016, 22:12
#
#В Raspberry Pi отсутствуют встроенные часы реального времени, а значит после выключения компьютера время сбрасывается, что не очень удобно.

#Решить данную проблему могут часы реального времени с памятью, питаемой от батарейки, и управляемые по шине i2c.
#Самыми популярными RTC являются часы на основе чипов DS1307,DS3231 и т.д. Я рекомендую часы на основе DS3231, т.к они одни из самых точных.

#Рассмотрим, как с ними работать:

$ echo ds3231 0x68 > /sys/class/i2c-adapter/i2c-1/new_device
#регистрируем часы в системе

#Для работы с RTC в Linux существует утилита hwclock
# hwclock -r - считать время, сохранённое в RTC
# hwclock -s - синхронизировать время системы с временем RTC
# hwclock -w - записать текущее системное время в RTC

#Таким образом, после того, как вы установите в системе точное время при помощи утилиты date (например date --set=”20140125 09:17:00”, если есть доступ к сети, то можно синхронизировать системное время с точным временем при помощи сетевой службы ntp - ntpd -gq), необходимо записать это время в RTC -
$ hwclock -w

#При каждой загрузке системы необходимо в качестве системного времени, устанавливать время, сохранённое в RTC.
#Для этого пропишите в /etc/rc.local перед exit0 следующие команды:
echo ds3231 0x68 > /sys/class/i2c-adapter/i2c-1/new_device
hwclock -s


#Опционально можно отключить синхронизацию системного времени через Интернет:
sudo update-rc.d ntp disable

# ПРОЧИТАТЬ ТЕМПЕРАТУРУ ИЗ DS3231

# 1
# Once your module is loaded it is recognised by the sensors command (package lm-sensors).

$ sudo apt-get install lm-sensors
$ sensors
# ds3231-i2c-1-68
# Adapter: 3f804000.i2c
# temp1: +21.5°C

#2
# Simply read the following file: /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon0/temp1_input (note that this is on a Raspberry Pi 2, it might be different path on older Raspberry Pies, my DS3231 is exposed on address 68 on SPI2 bus and I'm also running Raspbian Jessie with Kernel 4.8).

$ sudo apt-get install bc
$ echo "$(cat /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon0/temp1_input)/1000" | bc -l

############## AUTORUN PY SCRIPTS ON STARTUP ###################################################
Start your bot automatically at Raspberry Pi boot

Let’s create startup script in the telepot root folder:

sudo nano /home/pi/telepot/telegrambot.sh

Add the following lines:

#!/bin/sh
sleep 10
sudo python /home/pi/telepot/telegrambot.py

Hit CTRL + X, press Y, press Enter. Add some execute permissions:

sudo chmod +x /home/pi/telepot/telegrambot.sh

Now we need this script to run at boot. Edit rc.local:

sudo nano /etc/rc.local

Add these lines at the bottom:

/home/pi/telepot/telegrambot.sh &

exit 0

Hit CTRL + X, press Y, press Enter

#####################################################################
