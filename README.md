# NumerixHostLibrary
A library of host I/O routines, including full source code. Functions include console and File I/O,
including .WAV files. These functions can be used on any OS (UNIX, Windows etc.) and also on any
other embedded processor or DSP that supports console and file I/O via the debug environment.
These functions can also be used with Gnuplot/C to run any of the SigLib example programs.




               Numerix Host Library


                  Version 3.60

                   13/07/2021



INTRODUCTION

The Numerix Host Library (NHL) is a C/C++ library of console and file
I/O functions for DSP and data processing.

This library can be used on all host OSs - Unix, Windows etc. and
almost any embedded processor or DSP, where the debug environment
provides stdio functionality.


INSTALLATION

The library requires the following installation process :

Create a directory on the hard disk e.g. C:\NHL or /nhl
from this directory extract the archive and read the Reference Guide
(NHLRef.pdf) to find the appropriate batch / make or project file to
rebuild the library.

			IMPORTANT
After installation please ensure that the library and include file
directories are included in the compiler; library and include paths.


DOCUMENTATION

The documentation for the NHL is provided in Adobe Acrobat PDF format.
Readers for this file format for almost any operating system can be
obtained from the Adobe World Wide Web site :

http://www.adobe.com

Numerix Ltd. hopes you will find this product useful, if so then please
tell others otherwise if you have any comments or suggestions then
please tell us.


CHANGE LOG

V3.60       .h C/C++ header file write functions added

V3.50       .bin file read/write functions added

V3.40       .wav file read/write functions extended to support multi-channel
            .dat file read/write functions tidied up

V3.30       Additional .wav file read/write functions
            Standard 32 bit integer data types changed from long to int

V3.21       Tidied up examples

V3.20       Added XMOS .xmt file input functions

V3.10       Added .bin file I/O functions
            Added .csv file I/O functions
            buffer_to_disk() replaced by sig_write_data()
            buffer_from_disk() replaced by sig_read_data()


LICENSE

This software is free for use in any application but Sigma Numerix Ltd does
not provide any warranty or support.


SigLib and Digital Filter Plus are trademarks of Sigma Numerix Ltd. all other
trademarks acknowledged.


For additional information, please contact :

Sigma Numerix Ltd.,
Email : support@numerix-dsp.com
WWW : http://www.numerix-dsp.com

(C) Copyright 2017 Sigma Numerix Ltd.
