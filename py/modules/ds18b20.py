import os
import glob
import time
 
ds18b20_file = glob.glob('/sys/bus/w1/devices/28*')[0] + '/w1_slave'
 
os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
 
while True:
    f = open(ds18b20_file, 'r')
    lines = f.readlines()
    f.close()
    
    ds18b20_temp = float(lines[1][lines[1].find('t=')+2:]) / 1000.0
    
    print(ds18b20_temp)
    
    time.sleep(560)
