// .SIG to .WAV file conversion program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <nhl.h>

double  *p_DataArray;
#define SAMPLE_SIZE     128

WAV_FILE_INFO WavInfo;

long xmt_read_data (double *BPtr,
    FILE *FPtr,
    const long BufLen);


int main( int argc, char **argv )
{
    long    sampleCount;
    FILE    *pInputFile, *pOutputFile;
    long    TotalsampleCount = 0;

    char    XmtFileName[80];
    char    WavFileName[80];

    if (argc != 3) {
        printf("Useage : xmt2wav filename samplerate\nSample rates : 8000, 22050, 44100 etc.");
        exit (1);
    }

    strcpy (XmtFileName, argv[1]);
    strcat (XmtFileName, ".xmt");

    strcpy (WavFileName, argv[1]);
    strcat (WavFileName, ".wav");

    printf ("xmt filename = %s\n", XmtFileName);
    printf ("wav filename = %s\n", WavFileName);

    p_DataArray = (double *)malloc (SAMPLE_SIZE * sizeof (double));

    if ((pInputFile = fopen(XmtFileName, "rb")) == NULL) {  // Note this file is binary
        printf ("Error opening input .xmt file\n");
        exit (1);
    }

    if ((pOutputFile = fopen(WavFileName, "wb")) == NULL) { // Note this file is binary
        printf ("Error opening output .wav file\n");
        exit (1);
    }

    WavInfo = wav_set_info (atol (argv[2]), 0, 1, 16, 2, 1);

    wav_write_header (pOutputFile, WavInfo);                // Write dummy header to output file

    while ((sampleCount = xmt_read_data (p_DataArray, pInputFile, SAMPLE_SIZE)) != 0) { // Successively read arrays of 128 samples*/
        for (int i = 0; i < sampleCount; i++) {             // Scale the data to 16 bit (from 32 bit)
            *(p_DataArray+i) = *(p_DataArray+i) / (65536.);
        }
        TotalsampleCount += sampleCount;
        wav_write_data (p_DataArray, pOutputFile, WavInfo, sampleCount);
    }
                                                            // Write last block of data
    printf ("Total number of samples read = %d\n", TotalsampleCount);

    WavInfo.NumberOfSamples = TotalsampleCount;             // Set total data length
    rewind (pOutputFile);                                   // Rewind pointer to start of file
    wav_write_header (pOutputFile, WavInfo);                // Overwrite the header information

    fclose (pInputFile);
    fclose (pOutputFile);

    free (p_DataArray);                                     // Free memory

    return (0);
}

