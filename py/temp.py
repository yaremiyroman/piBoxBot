# -*- coding: utf-8 -*-
import os
import time

delay = 1

#####################################################################

while True:
    temp = os.popen("vcgencmd measure_temp").readline()
    os.system('clear')

    print '*************************************************************************'
    print ''
    print ''
    print ''
    print ''
    print ''
    print ''
    print ''
    print '  ' + temp
    print ''
    print ''
    print ''
    print ''
    print ''
    print ''
    print '*************************************************************************'

    time.sleep(delay)
