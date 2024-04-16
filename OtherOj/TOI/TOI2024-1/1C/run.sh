#/usr/bin/zsh
g++ -g -Wall -Wextra -Wshadow -fsanitize=undefined,address 1C_sample.cpp stub.cpp -o grader
echo "done"
./grader
