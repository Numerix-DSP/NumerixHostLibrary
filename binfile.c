/**************************************************************************
File Name       : BINFILE.C             | Author        : JOHN EDWARDS
Library version : 3.20                  | Modifications :
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
Description : Buffer I/O to disk functions.

****************************************************************************/

// Include files

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "nhl.h"


/**/
/********************************************************
* Function : bin_write_data
*
* Parameters :
*   const double *bp,   - Buffer pointer
*   FILE *fp,           - File pointer
*   const char endianMode,
*   const int buffer_length
*
* Return value :
*   void
*
* Description : Write a buffer of data to a .bin file.
*
********************************************************/

void bin_write_data (const double *bp,
    FILE *fp,
    const char endianMode,
    const int buffer_length)

{
    int    i;

    for (i = 0; i < buffer_length; i++) {
        if ((endianMode == 'b') || (endianMode == 'b')) {
            fputc(((short)*bp >> 8) & 0xff, fp);
            fputc((short)*bp++ & 0xff, fp);
        }
        else {
            fputc((short)*bp & 0xff, fp);
            fputc(((short)*bp++ >> 8) & 0xff, fp);
        }
    }
}       // End of bin_write_data ()




/**/
/********************************************************
* Function : bin_read_data
*
* Parameters :
*   double *bp, - Buffer pointer
*   FILE *fp,   - File pointer
*   const char endianMode,
*   const int  buffer_length
*
* Return value :
*   int    sample_count    - Number of samples read
*
* Description : Read a buffer of data from a .bin file.
*
********************************************************/

int bin_read_data (double *bp,
    FILE *fp,
    const char endianMode,
    const int buffer_length)

{
    int     i = 0;
    int     sample_count = 0;
    short   int_1, int_2, out_val;

    for (i = 0; ((i < buffer_length) && ((int_1 = fgetc(fp)) != EOF)); i++) {
        int_2 = fgetc(fp);

        if (int_2 == EOF) {
            break;
        }

        if ((endianMode == 'b') || (endianMode == 'b')) {
            out_val = (int_1 & 0xff) << 8;
            out_val |= (int_2 & 0xff);
        }
        else {
            out_val = (int_2 & 0xff) << 8;
            out_val |= (int_1 & 0xff);
        }
        *bp++ = (double)out_val;
        sample_count++;
    }

    for (; (i < buffer_length); i++) {
        *bp++ = 0.0;
    }

    return (sample_count);
}       // End of bin_read_data ()

