#! /usr/bin/zsh
g++ -g -fsanitize=undefined,address -O2 -Wall -Wextra -Wshadow -std=gnu++17 -o grader grader.cpp Ali.cpp Benjamin.cpp
./grader
