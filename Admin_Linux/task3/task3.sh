#!/bin/bash
if [ -f "/home/$USERNAME/.bashrc" ]; then
    echo "the .bashrc file exists in the user home directory."
    export HELLO=$HOSTNAME >> /home/$USERNAME/.bashrc
    LOCAL=whoami >> /home/$USERNAME/.bashrc
    gnome-terminal
 else 
    echo "the .bashrc file dosnt exist in the user home directory."
 fi    	
