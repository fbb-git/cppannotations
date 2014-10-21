#!/bin/bash

for x in `cat $1`
do
    echo $x
    g++ --std=c++11 -c $x
done
