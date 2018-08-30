import config
import time
from picamera import PiCamera

####################### PHOTO CAPTURE LOOP #################################
camera = PiCamera()

def one_shot_photo():
  try:
      camera.start_preview()
      time.sleep(5)
      camera.capture('/home/pi/Pictures/cam/box_' + time.strftime("%d_%m_%y__%H_%M_%S") + '.jpg')
  finally:
      camera.stop_preview()
      camera.close()

# def make_photo():
#     print('make_photo > ')
#     camera.start_preview()
#     time.sleep(5)
#     camera.capture('/home/pi/Pictures/cam/box_' + time.strftime("%d_%m_%y__%H_%M_%S") + '.jpg')
#     time.sleep(5)
#     camera.stop_preview()

# loop_id = 1

# while True:
#     print('Loop #' + str(loop_id) + ' > ')
#     make_photo()
#     time.sleep(config.delay)
#     loop_id += 1
