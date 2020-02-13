#!/bin/bash

testsNumber=10
executable=tema1
total=0

make 

if test ! -x $executable; then
    echo "Executable file missing."
    exit 1
fi
mkdir -p output
for i in $(seq 1 $testsNumber); do
	./$executable < input/in$i > output/out$i
	diff -wb output/out$i output_ref/out$i > /dev/null 
	if [ $? -eq 0 ]; then
		echo "Test $i .......................... passed"
		sum=$(($sum + 10))
	else
		echo "Test $i .......................... failed"
	fi
done
echo ""
echo "TOTAL: $sum/100 puncte"
