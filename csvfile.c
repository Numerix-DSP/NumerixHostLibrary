/**************************************************************************
File Name       : CSVFILE.C             | Author        : JOHN EDWARDS
Library version : 3.10                  | Modifications :
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
Description : .csv file I/O routines

Columns
    Time    Amplitude

****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "nhl.h"

/**/
/********************************************************
* Function : csv_read_data
*
* Parameters :
*   double *pData,               - Output buffer pointer
*   FILE *FPtr,                 - File pointer
*   const double sampleRate,    - Sample rate
*   const int BufLen
*
* Return value :
*   int SampleCount    - Number of samples read
*   Returns SampleCount = 0 on error
*
* Description : Read a buffer of data from a .dat file.
*
********************************************************/

int csv_read_data (double *pData,
    FILE *FPtr,
    const double sampleRate,
    const int BufLen)

{
    int    i;
    int    SampleCount = 0;
    double  sample;
    double  samplePeriod = 1. / sampleRate;

    for(i = 0; i < BufLen; i++) {       // Write the data
        fscanf(FPtr, "%lf,%lf\n", &samplePeriod, &sample);
        if (feof (FPtr)) {              // Check end of file error
            return (SampleCount);
        }

        else {
            *pData++ = sample;
            SampleCount++;
        }
    }

    return (SampleCount);

}       // End of csv_read_data ()




/**/
/********************************************************
* Function : csv_write_data
*
* Parameters :
*   const double *pData,         - Buffer pointer
*   FILE *FPtr,                 - File pointer
*   const double sampleRate,    - Sample rate
*   const double sampleIndex,   - Sample index
*   const int BufLen
*
* Return value :
*   int sample_count   - Number of samples written
*
* Description : Write a buffer of data to a .dat file.
*
********************************************************/

int csv_write_data (const double *pData,
    FILE *FPtr,
    const double sampleRate,
    const int sampleIndex,
    const int BufLen)

{
    int    i;
    double samplePeriod = 1. / sampleRate;

    for(i = 0; i < BufLen; i++) {   // Write the data
        fprintf(FPtr, "%1.7lf,%lf\n", ((double)(sampleIndex + i))*samplePeriod, pData[i]);
    }

    return (i);

}       // End of csv_write_data ()

