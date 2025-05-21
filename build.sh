#!/bin/bash


if [ "$1" == "all" ]; then
    echo "Build encode program."
    cd src
    make all
fi
if [ "$1" == "run" ]; then
    echo "Run encode program."
    cd build
    ./encode $2
fi
if [ "$1" == "clean" ]; then
    echo "Clean program."
    cd src
    make clean
fi

exit 0