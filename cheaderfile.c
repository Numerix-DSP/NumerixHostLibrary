/**************************************************************************
File Name       : CHEADERFILE.C         | Author        : JOHN EDWARDS
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
Description : .h file write routines

    .h file header format

****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "nhl.h"


/**/
/********************************************************
* Function : cheader_write_file_double
*
* Parameters :
*   const double *pData,     - Buffer pointer
*   const char *fileName,   - File name
*   const int BufLen
*
* Return value :
*   int sample_count        - Number of samples written
*
* Description : Write a buffer of float data to a .h file.
*
********************************************************/

int cheader_write_file_double (const double *pData,
    const char *fileName,
    const int BufLen)

{
    FILE *fp;
    int i;

    if ((fp = fopen(fileName, "w")) == NULL) {
        return (-1);
    }

    fprintf(fp, "// Floating point data\n\n");      // Write header
    fprintf(fp, "#define TEST_ARRAY_LENGTH %d\n\n", BufLen);
    fprintf(fp, "double test_array_float[] = {\n");


    for(i = 0; i < BufLen-1; i++) {                 // Write the data
        fprintf(fp, "    %1.7lf,\n", pData[i]);
    }
    fprintf(fp, "    %1.7lf\n", pData[i]);

    fprintf(fp, "};\n\n");                          // Write footer

    fclose (fp);

    return (i);

}       // End of cheader_write_file_double ()


/**/
/********************************************************
* Function : cheader_write_file_int
*
* Parameters :
*   const int *pData,        - Buffer pointer
*   const char *fileName,   - File name
*   const int BufLen
*
* Return value :
*   int sample_count        - Number of samples written
*
* Description : Write a buffer of integer data to a .h file.
*
********************************************************/

int cheader_write_file_int (const int *pData,
    const char *fileName,
    const int BufLen)

{
    FILE *fp;
    int i;

    if ((fp = fopen(fileName, "w")) == NULL) {
        return (-1);
    }

    fprintf(fp, "// Integer data\n\n");             // Write header
    fprintf(fp, "#define TEST_ARRAY_LENGTH %d\n\n", BufLen);
    fprintf(fp, "int test_array_int[] = {\n");


    for(i = 0; i < BufLen-1; i++) {                 // Write the data
        fprintf(fp, "    %d,\n", pData[i]);
    }
    fprintf(fp, "    %d\n", pData[i]);

    fprintf(fp, "};\n\n");                          // Write footer

    fclose (fp);

    return (i);

}       // End of cheader_write_file_int ()

/**/
/********************************************************
* Function : cheader_write_file_double_byte_array
*
* Parameters :
*   const double *pData,     - Buffer pointer
*   const char *fileName,   - File name
*   const int BufLen
*
* Return value :
*   int sample_count        - Number of samples written
*
* Description : Write a buffer of float data to a .h file.
*
********************************************************/

int cheader_write_file_double_byte_array (const double *pData,
    const char *fileName,
    const int BufLen)

{
    FILE *fp;
    char *pChar = (char *)pData;
    int i;

    if ((fp = fopen(fileName, "w")) == NULL) {
        return (-1);
    }

    fprintf(fp, "// Byte array of floating point data\n\n");    // Write header
    fprintf(fp, "#define TEST_ARRAY_LENGTH %d\n\n", BufLen * (int)sizeof (double));
    fprintf(fp, "double test_array_float_byte_array[] = {\n");


    for(i = 0; i < (BufLen * sizeof (double))-1; i++) {         // Write the data
        fprintf(fp, "    %d,\n", pChar[i]);
    }
    fprintf(fp, "    %d\n", pChar[i]);

    fprintf(fp, "};\n\n");                                      // Write footer

    fclose (fp);

    return (i / sizeof (double));

}       // End of cheader_write_file_double_byte_array ()


/**/
/********************************************************
* Function : cheader_write_file_int_byte_array
*
* Parameters :
*   const int *pData,        - Buffer pointer
*   const char *fileName,   - File name
*   const int BufLen
*
* Return value :
*   int sample_count        - Number of samples written
*
* Description : Write a buffer of integer data to a .h file.
*
********************************************************/

int cheader_write_file_int_byte_array (const int *pData,
    const char *fileName,
    const int BufLen)

{
    FILE *fp;
    char *pChar = (char *)pData;
    int i;

    if ((fp = fopen(fileName, "w")) == NULL) {
        return (-1);
    }

    fprintf(fp, "// Byte array of integer data\n\n");   // Write header
    fprintf(fp, "#define TEST_ARRAY_LENGTH %d\n\n", BufLen * (int)sizeof (int));
    fprintf(fp, "int test_array_int_byte_array[] = {\n");


    for(i = 0; i < (BufLen * sizeof (int))-1; i++) {    // Write the data
        fprintf(fp, "    %d,\n", pChar[i]);
    }
    fprintf(fp, "    %d\n", pChar[i]);

    fprintf(fp, "};\n\n");                              // Write footer

    fclose (fp);

    return (i / sizeof (int));

}       // End of cheader_write_file_int_byte_array ()

