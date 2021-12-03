#! /bin/bash

if ! [ -d "./build" ]
then
  mkdir "build"
else
  rm -rf ./build
  mkdir "build"
fi

cd ./build
cmake ..
make

if [ "$1" == "run" ]
then
  ./$2 < input
fi 






