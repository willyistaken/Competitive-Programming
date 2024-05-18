#!/usr/bin/zsh
for ((i=0;;i++))
do
./gen > case.in
./B < case.in > aout
./B2 < case.in > bout

if ! (cmp -s aout bout);
then
cat case.in
fi

echo i

done

