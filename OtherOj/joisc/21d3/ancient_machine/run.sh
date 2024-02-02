#! /usr/bin/zsh
g++ -std=gnu++17 -O2 -fsigned-char -o grader grader.cpp Anna.cpp Bruno.cpp
echo "compiled"
./grader
