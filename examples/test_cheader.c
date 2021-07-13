// test_cheader.c

// Include files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nhl.h"


// Define constants
#define SAMPLE_LENGTH       10

// Declare global variables and arrays
double  srcDataFloat[SAMPLE_LENGTH] = {10., 11., 12., 13., 14., 15., 16., 17., 18., 19.};
int     srcDataInt[SAMPLE_LENGTH] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

int main (void)

{
    int     sampleCount;

    printf ("Opening and writing to test_file_float.h file\n");
    sampleCount = cheader_write_file_double (srcDataFloat, "test_file_float.h", SAMPLE_LENGTH);     // Write array to header - floating point format
    printf ("\n\n");

    printf ("Opening and writing to test_file_int.h file\n");
    sampleCount = cheader_write_file_int (srcDataInt, "test_file_int.h", SAMPLE_LENGTH);            // Write array to header - integer format
    printf ("\n\n");

    printf ("Opening and writing to test_file_float.h file\n");
    sampleCount = cheader_write_file_double_byte_array (srcDataFloat, "test_file_float_byte_array.h", SAMPLE_LENGTH);   // Write array to header - floating point format
    printf ("\n\n");

    printf ("Opening and writing to test_file_int.h file\n");
    sampleCount = cheader_write_file_int_byte_array (srcDataInt, "test_file_int_byte_array.h", SAMPLE_LENGTH);  // Write array to header - integer format
    printf ("\n\n");

    return (0);
}

