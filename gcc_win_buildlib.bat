@echo off

rem Batch file for building library with the GCC compiler under Windows

del /Q libnhl.a

gcc -O3 -std=c99 -c *.c
ar cr libnhl.a binfile.o csvfile.o datfile.o dspconio.o sigfile.o wavfile.o xmtfile.o

del *.o

