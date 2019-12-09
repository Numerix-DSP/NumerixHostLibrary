// test_csv.c

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
    double  sampleRate = 8000.;                      // .csv file parameters
    long    sampleIndex = 0l;
    FILE    *fpInputFile, *fpOutputFile;

    printf ("Opening and writing to test.csv file\n");

    if ((fpOutputFile = fopen ("test.csv", "wb")) == NULL) {    // Note this file is binary
        printf ("Error opening output .csv file\n");
        exit (1);
    }

    sampleIndex += csv_write_data (srcData, fpOutputFile, sampleRate, sampleIndex, IO_LENGTH);      // Write successive blocks of data
    sampleIndex += csv_write_data (srcData+IO_LENGTH, fpOutputFile, sampleRate, sampleIndex, IO_LENGTH);
    fclose (fpOutputFile);

    printf ("Opening and reading from test.csv file\n");

    if ((fpInputFile = fopen ("test.csv", "rb")) == NULL) {     // Note this file is binary
        printf ("Error opening input .csv file\n");
        exit (1);
    }

    while ((SampleCount = (int)csv_read_data (inputData, fpInputFile, sampleRate, IO_LENGTH)) == IO_LENGTH) {
        for (int i = 0; i < SampleCount; i++)
            printf ("%lf, ", inputData[i]);
    }

    fclose (fpInputFile);
    printf ("\n\n");

    return (0);
}

