#! /usr/bin/zsh
g++ -g -fsanitize=undefined,address -O2 -Wall -Wextra -Wshadow -std=gnu++17 -o grader2 grader.cpp Ali2.cpp Benjamin2.cpp
./grader2

