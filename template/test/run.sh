#! /usr/bin/zsh
for i in {1..1000}
do
	./gen > testcase
	./A < testcase >> testcase
	./checker < testcase >> result
done
