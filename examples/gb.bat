@echo off

rem Batch file for building and executing client application with GCC

del %1.exe
gcc %1.c -Wall -std=c99 -I.. ../libnhl.a -o %1.exe
