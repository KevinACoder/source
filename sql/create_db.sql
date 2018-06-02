mysql -u root -p #login
CREATE DATABASE temps #create db
USE temps
CREATE USER 'administrator'@'localhost' IDENTIFIED BY 'password'; #create user with password
FLUSH PRIVILEGES;
quit

mysql -u administrator -p #re-log in -'password'
#create table
USE temps;
CREATE TABLE tempdata (tdate DATE, ttime TIME, zone TEXT, temperature NUMERIC);