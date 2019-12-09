/**************************************************************************
File Name       : SIGFILE.C             | Author        : JOHN EDWARDS
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
Description : Buffer I/O to disk functions.

****************************************************************************/

// Include files

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "nhl.h"


/**/
/********************************************************
* Function : sig_write_data
*
* Parameters :
*   const double *bp,   - Buffer pointer
*   FILE *fp,           - File pointer
*   const int buffer_length
*
* Return value :
*   void
*
* Description : Write a buffer of data to a file.
*
********************************************************/

void sig_write_data (const double *bp,
    FILE *fp,
    const int buffer_length)

{
    int    i;

    for (i = 0; i < buffer_length; i++) {
        fprintf (fp, "%le\n", *bp++);               // Some compilers / OSs need \r\n
    }
                                                    // others just \n
}       // End of sig_write_data ()




/**/
/********************************************************
* Function : sig_read_data
*
* Parameters :
*   double *bp, - Buffer pointer
*   FILE *fp,   - File pointer
*   const int  buffer_length
*
* Return value :
*   int    sample_count    - Number of samples read
*
* Description : Read a buffer of data from a file.
*
********************************************************/

int sig_read_data (double *bp,
    FILE *fp,
    const int buffer_length)

{
    int    i;
    int    sample_count = 0;

    for (i = 0; ((i < buffer_length) && (fscanf (fp, "%le\n", bp) != EOF)); i++) {
        bp++;
        sample_count++;
    }

    for (; (i < buffer_length); i++) {
        *bp++ = 0.0;
    }

    return (sample_count);
}       // End of sig_read_data ()

