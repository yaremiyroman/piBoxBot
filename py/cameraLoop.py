import config
import time
from picamera import PiCamera

####################### PHOTO CAPTURE LOOP #################################
camera = PiCamera()
loopCamera = True

while loopCamera:
    try:
        camera.start_preview()
        time.sleep(5)
        camera.capture('/home/pi/Pictures/cam/box_' + time.strftime("%d_%m_%y__%H_%M_%S") + '.jpg')
    finally:
        camera.stop_preview()
        camera.close()
    time.sleep(config.delay)
