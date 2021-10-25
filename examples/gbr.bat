@echo off

rem Batch file for building and executing client application with GCC

del %1.exe
REM gcc %1.c -Wall -I.. -L ../nhl
gcc %1.c -Wall -std=c99 -I.. ../libnhl.a -o %1.exe
if exist %1.exe %1 %2 %3 %4 %5 %6 %7 %8 %9
