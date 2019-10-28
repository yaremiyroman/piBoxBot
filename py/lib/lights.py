# PIRAHNIA_1 = 5
# PIRAHNIA_2 = 6
# GPIO.setup(PIRAHNIA_1, GPIO.OUT)
# GPIO.output(PIRAHNIA_1, GPIO.LOW)
# GPIO.setup(PIRAHNIA_2, GPIO.OUT)
# GPIO.output(PIRAHNIA_2, GPIO.LOW)

####################### LIGHTS ##############################################
@bot.message_handler(commands=['lights'])
def switch_lights(message):
    senderID = message.chat.id
    
    if GPIO.input(PIRAHNIA_1) == 0:
        bot.send_message(senderID, 'Turning on...')
        # GPIO.output(PIRAHNIA_1, GPIO.HIGH)
        # time.sleep(rest)
        # GPIO.output(PIRAHNIA_2, GPIO.HIGH)
    else:
        bot.send_message(senderID, 'Lights off!!')
        # GPIO.output(PIRAHNIA_1, GPIO.LOW)
        # time.sleep(rest)
        # GPIO.output(PIRAHNIA_2, GPIO.LOW)

    time.sleep(delay)
