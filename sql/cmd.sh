sudo mysql -u root

//uninstall and install mysql
sudo apt-get remove --purge mysql\*
//check existence of mysql
sudo dpkg -l | grep -i mysql
//install mysql
sudo apt-get clean
sudo apt-get update
sudo apt-get install libmysqlclient-dev mysql-client
sudo apt-get install mysql-server
