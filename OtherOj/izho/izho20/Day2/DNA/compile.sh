#! /usr/bin/zsh
g++ -std=c++11 -O2 -o solution grader.cpp solution.cpp
echo "compiled"
./solution
