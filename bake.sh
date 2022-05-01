#!/bin/bash

PROJECT_NAME="gl"
COMPILER="g++"
LIBRARIES="-lglfw -pthread -ldl -lGLU -lGL -lGLEW -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11"

$COMPILER -c src/Main.cpp src/Classes/*.cpp
mkdir -p build
$COMPILER *.o -o build/$PROJECT_NAME -I src/Headers $LIBRARIES
rm *.o
