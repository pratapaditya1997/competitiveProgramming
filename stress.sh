#!/bin/bash

g++ solution.cpp -o solution -std=c++11
g++ brute.cpp -o brute -std=c++11
g++ gen.cpp -o gen

for ((i =1; ;i++)) do
    ./gen $i > in
    ./solution < in > out
    ./brute < in > out_brute

    if ! cmp -s out out_brute
    then
        echo 'found failing test!'
        break
    fi 

    echo 'OK'
done