#!/usr/bin/zsh
echo "start" > result.txt
for i in {0..200}
do
./gen > testcase.in
./B < testcase.in > Cout.txt
./B2 < testcase.in >> Cout.txt
./check < Cout.txt >> result.txt
done
