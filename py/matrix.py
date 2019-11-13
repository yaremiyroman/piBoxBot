# -*- coding: utf-8 -*-
import time
import luma

from luma.led_matrix.device import max7219
from luma.core.virtual import sevensegment
from luma.core.interface.serial import spi, noop
from luma.core.legacy import show_message
from luma.core.legacy.font import proportional, CP437_FONT

print('=== luma ===')
print(luma)

print('=== delay ===')
delay = 10
print(delay)

print('- defining matrix func -')
def matrix():
    print('- def matrix -')
    
    serial = spi(port=0, device=0, gpio=noop())
    print('- serial -')
    print(serial)
    
    device = max7219(serial, cascaded=1, block_orientation=0, rotate=0, blocks_arranged_in_reverse_order=False)
    print('- device -')
    print(device)
    
    print('- show_message -')
    show_message(device, "Hello Kitty^^", fill="white", font=proportional(CP437_FONT))
    print('- it was a message -')
    
    print('- timeout go -')
    time.sleep(delay)
    print('- timeout finished -')
    
    print('::::::: matrix func end :::::::')
    
print('- defining matrix_run -')
def matrix_run():
    print('- matrix_run -')
    try:
        while True:
            print('+++++ TRYING +++++')
            matrix()
            print('+++++ TRYING end +++++')
    except:
        print('!!! EXCEPTION !!!')
        time.sleep(delay)
        matrix()

print('- start matrix_run -')
matrix_run()
