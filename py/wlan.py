# -*- coding: utf-8 -*-
import os
import time
#from termcolor import colored
# {'blue': 34, 'grey': 30, 'yellow': 33, 'green': 32, 'cyan': 36, 'magenta': 35, 'white': 37, 'red': 31}

delay = 1

#####################################################################

while True:
    wlan0 = os.popen("iwconfig wlan0 | grep 'Signal level'").readline().split()
    os.system('clear')

    print '^^^^^^^^^^^^^^^^^^^'
    print ''
    print ''
    print ''
    print '*******************'
    print '     ' + wlan0[3]
    print '*******************'
    print ''
    print ''
    print ''
    print '==================='

    time.sleep(delay)
