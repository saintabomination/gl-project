#!/bin/bash

PROJECT_NAME="gl"
COMPILER="g++"

$COMPILER -c src/Main.cpp
mkdir -p build
$COMPILER *.o -o build/$PROJECT_NAME
rm *.o
