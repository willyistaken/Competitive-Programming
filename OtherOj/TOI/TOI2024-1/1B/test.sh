#!/usr/bin/zsh
for ((i=1;;i++))
do
./gen > case.in
./A < case.in > result1
./B < case.in >  result2
if ! (cmp result1 result2);
then
cat case.in
fi
done
