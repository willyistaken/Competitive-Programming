#!/usr/bin/zsh

for ((i=0;i<500;i++))
do
./gen > testcase
./I < testcase > out1
./I2 < testcase > out2

if cmp --silent -- out1 out2; then
else
  cat testcase
  echo "!="
fi
done
