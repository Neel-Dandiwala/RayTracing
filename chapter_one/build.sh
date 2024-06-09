#!/bin/bash

# Define paths to SDL2 include and library directories
SDL2_INCLUDE_PATH=/d/Desktop/RayTracing/SDL2/x86_64-w64-mingw32/include
SDL2_LIB_PATH=/d/Desktop/RayTracing/SDL2/x86_64-w64-mingw32/lib  # Use /c/SDL2/lib/x86 for 32-bit systems

# Compile the program
g++ -g main.cpp -lSDL2
