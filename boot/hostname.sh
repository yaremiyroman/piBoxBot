echo "Type the new hostname";
echo "/etc/hostname";
sleep 5;

sudo nano /etc/hostname;
sleep 1;


echo "Change all occurances of the old hostname with the new hostname";
echo "/etc/hosts";
sleep 5;

sudo nano /etc/hosts;
sleep 1;
