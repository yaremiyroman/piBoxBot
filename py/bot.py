# -*- coding: utf-8 -*-
import os
import time
import math
import telebot
import io
import sqlite3

import config

#########################################################################
####################### INIT ###############################################
############################################################################

bot = telebot.TeleBot(config.token)
conn = sqlite3.connect('/home/pi/piBoxBot/db/unoClimate.db')
ADMINS = [config.adminID]

############################################################################
####################### BOT COMMANDS HANDLERS ##############################
############################################################################

####################### START ##############################################
@bot.message_handler(commands=['start'])
def say_hi(message):
    bot.send_message(message.chat.id, 'Привет bitch!')

####################### STATE ##############################################
@bot.message_handler(commands=['state'])
def show_system_state(message):
    sysname = os.uname().sysname
    release = os.uname().release
    machine = os.uname().machine

    uptime = os.popen("awk '{print $1}' /proc/uptime").readline()
    uptime_time = int(float(uptime))
    uptime_hrs = math.floor(uptime_time / 3600)
    uptime_mins = math.floor((uptime_time % 3600) / 60)

    df_data = os.popen('df -h /')
    line = df_data.readline()
    line = df_data.readline()
    disk_data = line.split()[0:6]

    core_temp = os.popen('vcgencmd measure_temp').readline().replace('temp=','').replace("'C\n", '°C')

    bot.send_message(message.chat.id, '-------------- System state ---------------')
    bot.send_message(message.chat.id, 'OS > ' + sysname + ' ' + release + ' ' + machine)
    bot.send_message(message.chat.id, 'Date@Time > ' + time.strftime('%a %d-%m-%y @ %H:%M'))
    bot.send_message(message.chat.id, 'Uptime > ' + str(uptime_hrs) + ' hr ' + str(uptime_mins) + ' min')
    bot.send_message(message.chat.id, 'Free space  > ' + disk_data[3])
    bot.send_message(message.chat.id, 'Core temperature > ' + core_temp)

####################### START ##############################################
@bot.message_handler(commands=['climate'])
def climate(message):
    ds18b20 = conn.execute("SELECT t FROM ds18b20 WHERE id IN (select max(id) FROM ds18b20)")
    bot.send_message(message.chat.id, 'ds18b20 t=' + ds18b20)

####################### START ##############################################
@bot.message_handler(commands=['photo'])
def photo(message):
    bot.send_message(message.chat.id, 'photo')
    
####################### REBOOT #############################################
@bot.message_handler(commands=['reboot'])
def reboot(message):
    sender_ID = message.chat.id
    if sender_ID not in ADMINS:
        bot.send_message(sender_ID, 'Go f*ck yourself')
        return
    bot.send_message(sender_ID, 'Rebooting --> ')
    os.system('sudo reboot')
    time.sleep(1)

# ####################### TURN OFF #############################################
@bot.message_handler(commands=['shutdown'])
def shutdown(message):
    sender_ID = message.chat.id
    if sender_ID not in ADMINS:
        bot.send_message(sender_ID, 'Go f*ck yourself')
        return
    bot.send_message(sender_ID, 'Going offline...')
    os.system('sudo shutdown -h now')
    time.sleep(1)

############################################################################
###################### POLLING ########################################
############################################################################

def telegram_polling():
    try:
        bot.polling(none_stop = True, timeout = 600)
    except:
        traceback_error_string=traceback.format_exc()
        with open("Error.Log", "a") as myfile:
            myfile.write("\r\n\r\n" + time.strftime("%c")+"\r\n<<ERROR polling>>\r\n"+ traceback_error_string + "\r\n<<ERROR polling>>")
        # conn.close()
        bot.stop_polling()
        time.sleep(30)
        telegram_polling()

if __name__ == '__main__':
    telegram_polling()
