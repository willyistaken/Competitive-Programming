#!/usr/bin/zsh
g++ -std=gnu++17 -g -fsanitize=undefined,address -O2 -Wall -Wextra -Wshadow -o grader grader.cpp Anna.cpp Bruno.cpp
echo "compiled"
./grader

