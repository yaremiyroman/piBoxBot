
######################### PHOTO ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    senderID = message.chat.id

    bot.send_message(senderID, 'Recent photo --> ')
    
    try:
        recent_photo = open('/home/pi/cam_telebot.jpg', 'rb')
        time.sleep(3)
    except Exception:
        bot.send_message(senderID, 'Try later :( ')
    else:
        bot.send_photo(senderID, recent_photo)
