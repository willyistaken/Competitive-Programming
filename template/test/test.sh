#!/usr/bin/zsh
for ((i=0;;i++))
do
./gen > case.in
./A < case.in > aout
./B < case.in > bout

if ! (cmp -s aout bout);
then
cat case.in
fi

done
