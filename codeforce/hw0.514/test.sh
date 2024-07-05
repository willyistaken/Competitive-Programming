#!/usr/bin/zsh

for ((i=0;i<500;i++))
do
./gen > testcase
./E < testcase > out1
./E2 < testcase > out2

if cmp --silent -- out1 out2; then
  echo "=="
else
  cat testcase
  echo "!="
fi
done
