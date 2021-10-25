/**************************************************************************
File Name       : NHL.H                 | Author        : JOHN EDWARDS
Library version : 3.60                  | Modifications :
----------------------------------------+----------------------------------
Compiler  : Independent                 | Start Date    : 22/01/00
Options   :                             | Latest Update : 13/07/21
---------------------------------------------------------------------------
This file may be modified, in any way, providing that this header remains
within the file and none of the header contents are removed or modified.

This software is provided as user supported software and with no warranty.

DELETION OF ANY INFORMATION IN THIS HEADER IS IN VIOLATION OF YOUR LICENSE.

Copyright (C) 2000 to 2021 Sigma Numerix Ltd.
---------------------------------------------------------------------------
Description : Header file for Numerix Host library

****************************************************************************/

#ifndef NUMERIX_HOST_LIBRARY                // If NUMERIX_HOST_LIBRARY not defined then declare it
#define NUMERIX_HOST_LIBRARY    1

#define NHL_VERSION             3.60        // Indicates NHL version being used

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifdef __cplusplus          // Declaration for C++ program calls
extern "C"
{
#endif


                    // Functions for writing to the console
void print_buffer (const double *, const int);              // Print contents of a buffer
void print_fixed_point_buffer (const int *ptr, const int size); // Print contents of a fixed point buffer
void print_matrix (const double *, const int, const int);   // Display a 2D matrix
#define print_polar(V)  printf("P = %le < %le\n", V.magn, V.angle);
#define print_rectangular(V)    printf("C = %le, j%le\n", V.real, V.imag)


                    // Functions for reading and writing .bin files
int     bin_read_data (double *, FILE *, const char, const int);                // double data
void    bin_write_data (const double *, FILE *, const char, const int);

                    // Functions for writing C/C++ .h files
int cheader_write_file_double (const double *, const char *, const int);              // double data
int cheader_write_file_int (const int *, const char *, const int);                    // integer data
int cheader_write_file_double_byte_array (const double *, const char *, const int);   // double data
int cheader_write_file_int_byte_array (const int *, const char *, const int);         // integer data

                    // Functions for reading and writing .csv files
int     csv_read_data (double *, FILE *, const double, const int);
int     csv_write_data (const double *, FILE *, const double, const int, const int);
double  csv_read_header (FILE *);

                    // Functions for reading and writing .dat files
int     dat_read_data (double *, FILE *, const int);
int     dat_write_data (const double *, FILE *, const double, const int, const int);
double  dat_read_header (FILE *);
int     dat_write_header (FILE *, const double);


                    // Functions for reading and writing .sig files
int     sig_read_data (double *, FILE *, const int);           // double data
void    sig_write_data (const double *, FILE *, const int);
int     sig_read_file (double *, const char *);
int     sig_write_file (const double *, const char *, const int);

int     xmt_read_data (double *, FILE *, const long);


                    // Functions for reading and writing .wav files
typedef struct {
    int     SampleRate;
    int     NumberOfSamples;
    short   NumberOfChannels;
    short   WordLength;
    short   BytesPerSample;
    short   DataFormat;
} WAV_FILE_INFO;

int wav_read_data (double *, FILE *, const WAV_FILE_INFO, const int);
void wav_write_data (const double *, FILE *, const WAV_FILE_INFO, const int);
short wav_read_word (FILE *);
int wav_read_int (FILE *);
void wav_write_word (const short, FILE *);
void wav_write_int (const int, FILE *);
WAV_FILE_INFO wav_read_header (FILE *);
void wav_write_header (FILE *, const WAV_FILE_INFO);
void wav_display_info (const WAV_FILE_INFO);
WAV_FILE_INFO wav_set_info (const int, const int, const short, const short, const short, const short);
int wav_file_length (const char *);
WAV_FILE_INFO wav_read_file (double *, const char *);
int wav_write_file (const double *, const char *, const WAV_FILE_INFO, const int);
int wav_write_file_scaled (const double *, char *, const WAV_FILE_INFO, const int);

#ifdef __cplusplus                  // End of decl. for C++ program calls
}
#endif

#endif
