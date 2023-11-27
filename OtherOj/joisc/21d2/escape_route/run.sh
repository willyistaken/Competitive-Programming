#! /usr/bin/zsh
g++ -ftrapv -g -fsanitize=undefined,address,float-cast-overflow,signed-integer-overflow -O2 -Wall -Wextra -Wshadow  -o grader grader.cpp escape_route.cpp 
echo "compiled"
./grader < case.in

