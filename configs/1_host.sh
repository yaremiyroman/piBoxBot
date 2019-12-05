#!/bin/sh

# ########################################################### #
# PASSWORD
# ########################################################### #
passwd  -u"pi";
sleep 3;

# ########################################################### #
# HOSTNAME
# ########################################################### #
CURRENT_HOSTNAME=`cat /etc/hostname | tr -d " \t\n\r"`;
NEW_HOSTNAME=$(whiptail --inputbox "Please enter a hostname" 10 40 ${CURRENT_HOSTNAME}  3>&1 1>&2 2>&3);
echo $NEW_HOSTNAME > /etc/hostname;
sed -i "s/127.0.1.1.*$CURRENT_HOSTNAME/127.0.1.1\t$NEW_HOSTNAME/g" /etc/hosts;
sleep 3;
