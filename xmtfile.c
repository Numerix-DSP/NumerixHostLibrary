/**************************************************************************
File Name       : XMTFILE.C             | Author        : JOHN EDWARDS
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
Description : .XMT file I/O routines

    .XMT file header format :

****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

/**/
/********************************************************
* Function : xmt_read_data
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
* Description : Read a buffer of data from a .xmt file.
*
********************************************************/

int xmt_read_data (double *BPtr,
    FILE *FPtr,
    const int BufLen)

{
    int     i;
    int     SampleCount = 0;
    int     fpsample;
    double  sample;
    char    lineArray[200];
    char    *p_char;

    for(i = 0; i < BufLen; i++) {                   // Write the data
        if (fgets(lineArray, sizeof(lineArray), FPtr) != NULL) {
            if ((p_char = strstr(lineArray, " User=")) != NULL) {
//              printf("The substring is: %s\n", p_char+7);
                sscanf (p_char+7, "%d\"/>\n", &fpsample);
                sample = (double)fpsample;
//              printf("sample = %lf\n", sample);
                *BPtr++ = sample;
                SampleCount++;
            }
        }
    }

    return (SampleCount);

}       // End of xmt_read_data ()

