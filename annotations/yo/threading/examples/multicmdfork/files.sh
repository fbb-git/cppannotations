#!/bin/bash

for x in `cat files.in`
do
    g++ --std=c++11 -c $x
done
