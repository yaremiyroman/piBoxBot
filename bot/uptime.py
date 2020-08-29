# -*- coding: utf-8 -*-
import os
import time
import math

uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
uptime_time = int(float(uptime))
uptime_hrs = math.floor(uptime_time / 3600)
uptime_mins = math.floor((uptime_time % 3600) / 60)
print('Uptime > ' + str(int(uptime_hrs)) + 'hr ' + str(int(uptime_mins)) + 'min')
