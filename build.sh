#!/bin/bash


if [ "$1" == "all" ]; then
    echo "Build encode program."
    cd src
    make all
fi
if [ "$1" == "run" ]; then
    echo "Run encode program."
    cd build
    ./manchester $2 $3 $4
fi
if [ "$1" == "ex1" ]; then
    echo "Run Example 1: echo -n a | ./encode | hexdump -C"
    cd build
    echo -n a | ./manchester | hexdump -C
fi
if [ "$1" == "ex2" ]; then
    echo "Run Example 2: echo 'hello' | ./encode"
    cd build
    echo 'hello' | ./manchester | hexdump -C
fi
if [ "$1" == "ex3" ]; then
    echo "Run Example 3: echo -n -e '\xff' | ./encode"
    cd build
    echo -n -e '\xff' | ./manchester | hexdump -C
fi
if [ "$1" == "clean" ]; then
    echo "Clean encode program."
    cd src
    make clean
fi

exit 0