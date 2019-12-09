// test_sig.c

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
    FILE    *fpInputFile, *fpOutputFile;

    printf ("Opening and writing to test.sig file\n");

    if ((fpOutputFile = fopen ("test.sig", "wb")) == NULL) {    // Note this file is binary
        printf ("Error opening output .sig file\n");
        exit (1);
    }

    sig_write_data (srcData, fpOutputFile, IO_LENGTH);          // Write successive blocks of data
    sig_write_data (srcData+IO_LENGTH, fpOutputFile, IO_LENGTH);
    fclose (fpOutputFile);

    printf ("Opening and reading from test.sig file\n");

    if ((fpInputFile = fopen ("test.sig", "rb")) == NULL) {     // Note this file is binary
        printf ("Error opening input .sig file\n");
        exit (1);
    }

    while ((SampleCount = (int)sig_read_data (inputData, fpInputFile, IO_LENGTH)) == IO_LENGTH) {
        for (int i = 0; i < SampleCount; i++)
            printf ("%lf, ", inputData[i]);
    }

    fclose (fpInputFile);
    printf ("\n\n");

    return (0);
}

