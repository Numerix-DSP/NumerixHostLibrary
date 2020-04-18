// test_dat.c

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
double          srcData[SAMPLE_LENGTH] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

int main (void)

{
    int     SampleCount;
    double  sampleRate = 8000.;                      // .dat file parameters
    long    sampleIndex = 0l;
    FILE    *fpInputFile, *fpOutputFile;

    printf ("Opening and writing to test.dat file\n");

    if ((fpOutputFile = fopen ("test.dat", "wb")) == NULL) {    // Note this file is binary
        printf ("Error opening output .dat file\n");
        exit (1);
    }

    dat_write_header (fpOutputFile, sampleRate);    // Write header - must be done ahead of writing data
    sampleIndex += dat_write_data (srcData, fpOutputFile, sampleRate, sampleIndex, IO_LENGTH);      // Write successive blocks of data
    sampleIndex += dat_write_data (srcData+IO_LENGTH, fpOutputFile, sampleRate, sampleIndex, IO_LENGTH);
    fclose (fpOutputFile);

    printf ("Opening and reading from test.dat file\n");

    if ((fpInputFile = fopen ("test.dat", "rb")) == NULL) {     // Note this file is binary
        printf ("Error opening input .dat file\n");
        exit (1);
    }

    sampleRate = dat_read_header (fpInputFile);
    printf ("Sample Rate = %lf\n", sampleRate);

    while ((SampleCount = (int)dat_read_data (inputData, fpInputFile, IO_LENGTH)) == IO_LENGTH) {
        for (int i = 0; i < SampleCount; i++)
            printf ("%lf, ", inputData[i]);
    }

    fclose (fpInputFile);
    printf ("\n\n");

    return (0);
}

