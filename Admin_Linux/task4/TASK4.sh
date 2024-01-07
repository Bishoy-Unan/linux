#!/bin/bash
echo "this script for creating user and group"
cd /
sudo adduser --force-badname Bishoy
sudo groupadd Younan
sudo usermod -aG Younan Bishoy
sudo cat /etc/group
echo "Younan group members is : "
sudo groupmems -g Younan -l