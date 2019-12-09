/**************************************************************************
File Name       : DATFILE.C             | Author        : JOHN EDWARDS
Library version : 3.40                  | Modifications :
----------------------------------------+----------------------------------
Compiler  : Independent                 | Start Date    : 22/01/00
Options   :                             | Latest Update : 26/06/16
---------------------------------------------------------------------------
This file may be modified, in any way, providing that this header remains
within the file and none of the header contents are removed or modified.

This software is provided as user supported software and with no warranty.

DELETION OF ANY INFORMATION IN THIS HEADER IS IN VIOLATION OF YOUR LICENSE.

Copyright (C) 2000 to 2017 Sigma Numerix Ltd.
---------------------------------------------------------------------------
Description : .DAT file I/O routines

    .DAT file header format :

; Sample Rate NNNN
; Channels 1

Columns
    Time    Amplitude

****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "nhl.h"

/**/
/********************************************************
* Function : dat_read_data
*
* Parameters :
*   double *BPtr,               - Output buffer pointer
*   FILE *FPtr,                 - File pointer
*   const int BufLen
*
* Return value :
*   int SampleCount    - Number of samples read
*   Returns SampleCount = 0 on error
*
* Description : Read a buffer of data from a .dat file.
*
********************************************************/

int dat_read_data (double *BPtr,
    FILE *FPtr,
    const int BufLen)

{
    int     i, j;
    int     SampleCount = 0;
    double  sample;
    double  samplePeriod = 0.;

    for(i = 0; i < BufLen; i++) {                   // Write the data
        int ret = fscanf(FPtr, " %lf %lf\n", &samplePeriod, &sample);

        if (feof (FPtr)) {                          // Check end of file error
            return (SampleCount);
        }

        else {
//          printf("sample = %lf\n", sample);
            *BPtr++ = sample;
            SampleCount++;
        }
    }

    return (SampleCount);

}       // End of dat_read_data ()


/**/
/********************************************************
* Function : dat_write_data
*
* Parameters :
*   const double *BPtr,         - Buffer pointer
*   FILE *FPtr,                 - File pointer
*   const double sampleRate,    - Sample rate
*   const int sampleIndex,      - Sample index
*   const int BufLen
*
* Return value :
*   int sample_count   - Number of samples written
*
* Description : Write a buffer of data to a .dat file.
*
********************************************************/

int dat_write_data (const double *BPtr,
    FILE *FPtr,
    const double sampleRate,
    const int sampleIndex,
    const int BufLen)

{
    int    i;
    double samplePeriod = 1. / sampleRate;

    for(i = 0; i < BufLen; i++) {                   // Write the data
        fprintf(FPtr, " %1.7lf %lf\n", ((double)(sampleIndex + i))*samplePeriod, BPtr[i]);
    }

    return (i);

}       // End of dat_write_data ()


/**/
/********************************************************
* Function : dat_read_header
*
* Parameters :
*   FILE *FPtr      - File pointer
*
* Return value :
*   sample rate
*
* Description : Read a .WAV file header section.
*
********************************************************/

double dat_read_header (FILE *FPtr)

{
    double  sampleRate;
    rewind (FPtr);
    fscanf(FPtr, "; Sample Rate %lf\n; Channels 1\n", &sampleRate);
    return (sampleRate);
}



/**/
/********************************************************
* Function : dat_write_header
*
* Parameters :
*   FILE *FPtr,         - File pointer
*   const double        - Sample rate
*
* Return value :
*   int Error code
*
* Description : Write a .WAV file header section.
*
********************************************************/

int dat_write_header (FILE *FPtr,
    const double sampleRate)

{
    rewind (FPtr);
    return (fprintf(FPtr, "; Sample Rate %d\n; Channels 1\n", (int)sampleRate));
}

