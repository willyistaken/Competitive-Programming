#!/usr/bin/zsh
for i in {1..50}; 
do
./gen > case.in
./A < case.in > result
./B < case.in >> result
./Comp < case.in < result >> dif
done
