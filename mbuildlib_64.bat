@echo off

rem Batch file for building the library with the Microsoft MSVC Compiler

del /Q nhl_64.lib

cl -c *.c
lib /NOLOGO /OUT:nhl64.lib *.obj

del *.obj

