/**************************************************************************
File Name       : DSPCONIO.C            | Author        : JOHN EDWARDS
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
Description : Display a buffer on the screen using standard text based I/O.

****************************************************************************/

// Include files

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nhl.h"


/**/
/********************************************************
* Function : print_buffer
*
* Parameters :
*   const double *ptr
*   const short size
*
* Return value :
*   void
*
* Description : Print out all values in a buffer
*
********************************************************/

void print_buffer (const double *ptr,
                const int size)

{
    register short  i;

    for (i = 0; i < (short)size; i++) {
        printf ("Buffer Location : %d, Value : %le   \n", i, *ptr++);

#if COMMENT                                         // Un-comment to display one sample at a time
        getch();
#endif
    }

}       // End of print_buffer()



/**/
/********************************************************
* Function : print_matrix
*
* Parameters :
*   const double *pSrc
*   const short NRows       - Number of rows
*   const short NCols       - Number of columns
*
* Return value :
*   void
*
* Description : Print out all values in a 2D matrix
*
********************************************************/

void print_matrix (const double *pSrc,
    const int NRows,
    const int NCols)

{
    register short  i, j;

    for (i = 0; i < (short)NRows; i++) {
        for (j = 0; j < (short)NCols; j++) {
            printf ("%le, ", *pSrc++);
        }
        printf ("\n");
    }
    printf ("\n");

}       // End of print_matrix()


