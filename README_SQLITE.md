# ########################################################### #
# ------------------       SQLite DB      ------------------- #
# ########################################################### #

$ BEGIN;

$ CREATE TABLE dht11_1 (id INTEGER PRIMARY KEY AUTOINCREMENT, t NUMERIC, h NUMERIC, date_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL);
$ DROP TABLE dht11_1;
$ INSERT INTO dht11_1 values(date('now'), time('now'), 27.50, 47.00);
$ SELECT * FROM dht11_1;
$ SELECT t FROM dht11_1 WHERE id="666";

$ COMMIT;
