#!/bin/bash

TASK=game

g++ -g -std=gnu++17 -Wall -Wextra -Wshadow -fsanitize=undefined,address -O2  -o ${TASK} grader.cpp ${TASK}.cpp
