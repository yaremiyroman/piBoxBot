-- create table
BEGIN;
CREATE TABLE ds18b20 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE dht11_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE dht22_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE moi_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE liquid (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE steam (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE rain (id INTEGER PRIMARY KEY AUTOINCREMENT, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
CREATE TABLE light (id INTEGER PRIMARY KEY AUTOINCREMENT, l NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
COMMIT;

BEGIN;
CREATE TABLE DHT22_1 (tdate DATE, ttime TIME, t NUMERIC, humidity NUMERIC);
COMMIT;

-- create table for DHT D4
BEGIN;
CREATE TABLE D4 (ttime TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL, t REAL, humidity REAL);
COMMIT;

-- add data
BEGIN;
INSERT INTO DHT22_1 values(date('now'), time('now'), 27.50, 47.00);
COMMIT;


-- get all
-- with condition:  WHERE zone="garage";
sqlite> SELECT * FROM DHT22_1;
-- 2013-09-04|01:41:08|garage|18.6
-- 2013-09-05|01:42:38|garage|19.1

--  selects only the 'temperature' field from each record:
sqlite> SELECT t FROM temps WHERE zone="garage";
-- 18.6

-- CORRECT TIME OUTPUT
SELECT DATETIME(date_time, 'localtime') FROM steam_1;


--  search for records from one day ago:
sqlite> SELECT * FROM temps WHERE tdate=date('now','-1 day');
-- 2013-09-04|01:40:36|kitchen|20.6
-- 2013-09-04|01:40:51|greenhouse|26.3
-- 2013-09-04|01:41:08|garage|18.6


-- search for records where the zone is the kitchen and the date is one day ago:
sqlite> SELECT * FROM temps WHERE zone="kitchen" AND tdate=date('now','-1 day');
-- 2013-09-04|01:40:36|kitchen|20.6


-- If we begin a transaction and query the data without a commit operation,
-- the data will be returned. If the ROLLBACK command is used and
--  we run the same query again, the data isn't returned:


BEGIN;
INSERT INTO temps values(date('now', '-2 day'), time('now'), "kitchen", 20.6);
SELECT * FROM temps WHERE zone="kitchen" AND tdate=date('now','-2 day');
2013-09-03|01:45:54|kitchen|20.6
ROLLBACK;
SELECT * FROM temps WHERE zone="kitchen" AND tdate=date('now','-2 day');


DROP TABLE database_name.table_name;
