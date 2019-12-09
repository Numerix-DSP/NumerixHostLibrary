@echo off

rem Batch file for building library with the Microsoft MSVC Compiler

del /Q nhl.lib

cl -c *.c
lib /NOLOGO /OUT:nhl.lib *.obj

del *.obj

