CREATE DATABASE IF NOT EXISTS lnunez-t_data;
CREATE USER IF NOT EXISTS 'lnunez-t'@'localhost' IDENTIFIED BY 'lnunez-t42';
GRANT ALL PRIVILEGES ON *.* TO 'lnunez-t'@'%' IDENTIFIED BY 'lnunez-t42';
ALTER USER 'root'@'localhost' IDENTIFIED BY 'lnunez-t42';
FLUSH PRIVILEGES;