#!/bin/bash
gcc -c *.c
ar r libnhl.a *.o
rm -f *.o
