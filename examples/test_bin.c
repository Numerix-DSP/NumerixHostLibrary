// test_bin.c

// Include files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "nhl.h"

// Define constants
#define IO_LENGTH           5
#define SAMPLE_LENGTH       10

// Declare global variables and arrays
double          inputData[SAMPLE_LENGTH];           // Data array pointers
double          srcData[SAMPLE_LENGTH] = {10., 11., 12., 13., 14., 15., 16., 17., 18., 19.};

int main (void)

{
    int     sampleCount;
    FILE    *fpInputFile, *fpOutputFile;

    printf ("Opening and writing to test_file.bin file\n");

    if ((fpOutputFile = fopen ("test_file.bin", "wb")) == NULL) {   // Note this file is binary
        printf ("Error opening output .bin file\n");
        exit (1);
    }

    bin_write_data (srcData, fpOutputFile, 'l', IO_LENGTH);         // Write successive blocks of data
    bin_write_data (srcData+IO_LENGTH, fpOutputFile, 'l', IO_LENGTH);
    fclose (fpOutputFile);

    printf ("Opening and reading from test_file.bin file\n");

    if ((fpInputFile = fopen ("test_file.bin", "rb")) == NULL) {    // Note this file is binary
        printf ("Error opening input .bin file\n");
        exit (1);
    }

    while ((sampleCount = (int)bin_read_data (inputData, fpInputFile, 'l', IO_LENGTH)) == IO_LENGTH) {
        for (int i = 0; i < sampleCount; i++)
            printf ("%lf, ", inputData[i]);
    }

    fclose (fpInputFile);
    printf ("\n\n");

    return (0);
}

