#! /usr/bin/zsh
g++ -ftrapv -g -fsanitize=undefined,address,float-cast-overflow,signed-integer-overflow -O2 -Wall -Wextra -Wshadow  -o grader2 grader.cpp escape_route2.cpp 
echo "compiled"
./grader2 < case.in > output2


