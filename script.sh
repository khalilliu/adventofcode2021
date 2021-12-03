#! /bin/bash

if [ "$1" == "create" ]
then
  if [ -e "./01/build" ]
  then
    rm -r ./01/build
  fi 
  
  cp -r 01 $2
fi
  