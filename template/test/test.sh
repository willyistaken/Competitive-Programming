#!/usr/bin/zsh
for i in {1..100}; 
do
./gen > case.in
./A < case.in > result
./B < case.in >> result
./Comp < case.in < result >> dif
done
