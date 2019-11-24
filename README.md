# pi setup ###########################################################################
# Download balenaEtcher app and flash microSD with Raspbian image
# Write an empty text file named "ssh" (no file extension) to the root of the directory of the card. When it sees the "ssh" on its first boot-up, Raspbian will automatically enable SSH
# Wi-Fi: create a text file called wpa_supplicant.conf near "ssh", Find piBoxBot/configs/wpa_supplicant.conf for example.ss
$ sudo raspi-conf
$ sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade && sudo apt-get autoremove && sudo apt-get autoclean
$ sudo apt-get install build-essential git git-core mc rpi.gpio wiringpi bc lm-sensors arduino arduino-mk python python-dev python-pip python3 python3-dev python3-pip sqlite3 libsqlite3-dev luvcview

###########################################
# configs
###########################################
$ sudo nano /etc/default/locale
$ sudo nano ~/.bashrc
$ sudo nano /etc/rc.local
$ sudo nano /boot/config.txt

###########################################
# SSH
###########################################
$ ssh-keygen -t rsa -b 4096 -C "yaremiyroman@gmail.com"
$ eval "$(ssh-agent -s)"
$ ssh-add ~/.ssh/id_rsa
$ cat ~/.ssh/id_rsa.pub
$ cat /Users/rx/.ssh/id_rsa.pub | ssh pi@piTest.local 'cat >> /home/pi/.ssh/authorized_keys'

###########################################
# git
###########################################
$ git config --global user.email "yaremiyroman@gmail.com" && git config --global user.name "andrdrx@piTest"
$ git@github.com:yaremiyroman/piBoxBot.git

###########################################
# info
###########################################
$ vcgencmd commands
$ stress --cpu 4

###########################################
# telebot
###########################################
$ pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT
$ mkdir piBoxBot/py/config

# create 'config' folder
$ pip install PyTelegramBotAPI==2.2.3 pysqlite Adafruit_DHT

###########################################
# RTC
###########################################
# /boot/config.txt
dtoverlay=i2c-rtc,ds3231
# /lib/udev/hwclock-set comment
if [ -e /run/systemd/system ] ; then
   exit 0
fi
$ hwclock -r, -w
$ sudo echo "$(cat /sys/class/i2c-adapter/i2c-1/1-0068/hwmon/hwmon1/temp1_input)/1000" | bc -l

##############################################################################
# luvcview: camera preview
##############################################################################
$ sudo apt-get install luvcview
$ luvcview

##############################################################################
# SQLite DB
##############################################################################
$ BEGIN;

$ CREATE TABLE ds18b20 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE dht11_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE dht22_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE moi_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE liquid (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE steam (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE rain (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ CREATE TABLE light (id INTEGER PRIMARY KEY AUTOINCREMENT, l NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);

$ DROP TABLE database_name.table_name;

$ SELECT * FROM DHT22_1;
$ INSERT INTO DHT22_1 values(date('now'), time('now'), 27.50, 47.00);
$ SELECT t FROM temps WHERE zone="garage";

# CORRECT TIME OUTPUT
$ SELECT DATETIME(date_time, 'localtime') FROM steam_1;
# records from one day ago
$ SELECT * FROM temps WHERE tdate=date('now','-1 day');
# records where the zone is the kitchen and the date is one day ago
$ SELECT * FROM temps WHERE zone="kitchen" AND tdate=date('now','-1 day');

$ COMMIT;

##############################################################################
# C reference
##############################################################################
# strtod
преобразование строки в число типа double.
# isnormal 
макрос проверяет, является ли аргумент конечным, нормализованным числом отличным от нуля
# trunc, truncf, truncl
округление до наибольшего целого, которое меньше или равно аргументу
# strtok
разбиение строки на части по указанному разделителю.
# strstr
поиск первого вхождения строки А в строку В.
# time
определение текущего времени в секундах.
# tan, tanf, tanl
расчет тангенса
# strspn
определение максимальной длины участка строки, содержащего только указанные символы.
# trspn
определение максимальной длины участка строки, содержащего только указанные символы.
# mstrncat
объединение строк c ограничением длины добавляемой строки.
# strncpy
копирование строк c ограничением длины.
# strlen
определение длины строки.
# strftime
перевод даты и времени в текстовую строку заданного формата.
# strdup
дублирование строк с выделением памяти под новую строку.
# strcpy
копирование строк
# strcmp
сравнение строк
# strchrnul
поиск первого вхождения символа в строкуmemmove – копирование массивов (в том числе пересекающихся)
# strchr
поиск первого вхождения символа в строку
# strcat
объединение строк
# strcasestr
поиск первого вхождения строки А в строку В без учета регистра символов
# sqrt, sqrtf, sqrtl
расчет квадратного корня
# signbit
определение знака числа
# setbuf
установка буферизации для записи в поток данных
# scalb, scalbf, scalbl
вычисление числа по мантиссе и порядку
# round, roundf, roundl
округление до ближайшего целого
# rint, rintf, rintl
округление до ближайшего целого
# remquo, remquof, remquol
вычисление частного и остатка от деления
# pthread_attr_getschedpolicy
опрос атрибута потока управления «стратегия планирования»
# pthread_attr_getschedparam
опрос атрибута потока управления «параметры планирования (приоритет)»
# pthread_attr_getinheritsched
опрос атрибута потока управления «наследование стратегии планирования»
# pthread_attr_getdetachstate
опрос атрибута потока управления «статус освобождения ресурсов»
# remainder, remainderf, remainderl
вычисление остатка от деления
# printf
вывод форматированной строки в стандартный поток вывода
# pow10, pow10f, pow10l
возведение числа 10 в степень.
# nexttoward, nexttowardf, nexttowardl
поиск ближайшего допустимого значения
# nextafter, nextafterf, nextafterl
поиск ближайшего допустимого значения
# nearbyint, nearbyintf, nearbyintl
округление до ближайшего целого
# modf, modff, modfl
разделение числа на целую и дробную части
# memset
заполнения массива указанными символами.
# memmove
копирование массивов (в том числе пересекающихся)
# memcpy
копирование непересекающихся массивов
# memcmp
сравнение массивов
# memchr
поиск первого вхождения указанного символа в массиве
# memccpy
копирование непересекающихся массивов
# lround, lroundf, lroundl
округление до ближайшего целого
# lrint, lrintf, lrintl
округление до ближайшего целого
# logb, logbf, logbl
выделение порядка числа с плавающей точкой
# log1p, log1pf, log1pl
расчет натурального логарифма от выражения 1+x
# log10, log10f, log10l
расчет десятичного логарифма
# log2, log2f, log2l
расчет логарифма по основанию два
# log, logf, logl
расчет натурального логарифма
# llround, llroundf, llroundl
округление до ближайшего целого
# llrint, llrintf, llrintl
округление до ближайшего целого
# ldexp, ldexpf, ldexpl
преобразуют число, заданное мантиссой и порядкой, в число с плавающей точкой
# islessgreater
макрос проверяет, справедливость отношения: (x < y) || (x>y)
# islessequal
макрос проверяет, справедливость отношения: x <= y
# isless
макрос проверяет, справедливость отношения: x < y
isinf, isinff, isinfl - проверка, является ли аргумент бесконечностью
# isgreaterequal
макрос проверяет справедливость отношения: x >= y
# isgreater
макрос проверяет справедливость отношения: x > y
# isfinite
макрос проверяет, является ли аргумент конечным числом
# ilogb, ilogbf, ilogbl
выделение порядка числа с плавающей точкой
# hypot, hypotf, hypotl
расчет расстояния от начала координат до заданной точки на плоскости.
# gmtime_r
вычисление UTC времени
# gmtime
вычисление UTC времени.
# frexp, frexpf, frexpl
разложение числа с плавающей точкой на мантиссу и порядок
# fputs
вывод строки в указанный поток данных
# fmod, fmodf, fmodl
вычисление остатка от деления
# fmin, fminf, fminl
определение меньшего значения из двух предложенных
# fmax, fmaxf, fmaxl
определение большего значения из двух предложенных
# fma, fmaf, fmal
расчет выражения a*b+c
# finite, finitef, finitel
проверяют, является ли аргумент конечным числом
# fdim, fdimf, fdiml
расчет положительной разности двух чисел
# exp10, exp10f, exp10l
возведение числа 10 в степень
# drem, dremf, dreml
вычисление остатка от деления
# сexp, сexpf, сexpl
возведение числа e в комплексную степень
