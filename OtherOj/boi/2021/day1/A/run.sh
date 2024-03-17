#!/usr/bin/zsh
g++ -g -Wall -Wextra -Wshadow -fsanitize=undefined,address grader.cpp books.cpp -o out 
echo "compiled"
./out < case.in



