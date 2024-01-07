#!/bin/bash
echo "Bishoy Unan"
echo "host name is :"
echo $HOSTNAME
echo "user name is : "
echo $USERNAME
read -p "please enter positive number: " number
re='^[0-9]+$'
if ! [[ $number =~ $re ]]; then
    echo "error : not apositive integer" >&2; exit 1
fi
    
iterator=1
echo "you enterd $number "
while [ $iterator -le $number ]
do
  square=$(($iterator * $iterator))
  echo "the square of $iterator is $square"
  iterator=$(($iterator + 1))
done