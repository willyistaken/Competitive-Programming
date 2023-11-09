#!/usr/bin/zsh
echo "start" > result.txt
for i in {0..200}
do
./gen > testcase.in
./C < testcase.in > Cout.txt
./testC < testcase.in >> Cout.txt
./check < Cout.txt >> result.txt
done

