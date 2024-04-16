#!/usr/bin/zsh
g++ -g -Wall -Wextra -Wshadow -fsanitize=undefined,address B.cpp sample_grader.cpp -o grader
echo "compiled"
./grader
