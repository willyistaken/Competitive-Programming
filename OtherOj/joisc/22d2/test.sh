#!/usr/bin/zsh
for i in {0..20}
do
./gen > testcase.in
./C < testcase.in > Cout.txt
./C2 < testcase.in >> Cout.txt
./check < Cout.txt >> result.txt
done
