#! /bin/bash

if ! [ -d "./build" ]
then
  mkdir "build"
else
  rm -rf ./build
  mkdir "build"
fi

cd ./build
cmake -Wno-dev ..
make 

if [ "$1" == "run" ]
then
  ./$2 < input
elif [ "$1" == "test" ]
then 
  ./$2 < input_test
fi 






