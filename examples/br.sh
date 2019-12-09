#!/bin/bash

# Bash script for building and running one of the examples

gcc -std=c99 $1.c -I.. ../libnhl.a -o $1

./$1
