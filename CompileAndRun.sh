#!/bin/bash

# This is a simple bash script to compile and run a cpp program
# the file's directory and the file's name are respectively the first and second argument

cd $1
g++ $2
./a.out