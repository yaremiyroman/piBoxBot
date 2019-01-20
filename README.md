# piBoxBot
# Disable sleep mode

# sudo nano /boot/config.txt
# power down monitor when lockscreen enabled
# hdmi_blanking=1

# sudo nano ~/.config/lxsession/LXDE-pi/autostart
# @xset s 0 0
# @xset s noblank
# @xset s noexpose
# @xset dpms 0 0 0

# sudo reboot
