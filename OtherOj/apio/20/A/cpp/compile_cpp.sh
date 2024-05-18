#!/bin/bash

problem=paint

g++ -g -Wall -Wextra -Wshadow -fsanitize=undefined,address -std=c++11 -o "${problem}" "grader.cpp" "${problem}.cpp" -O2 -lm
