/**
 * resize.c
 * date revised: 2022 Feb 23,
 * date created: 2016 June 02
 * 
 * Computer Science 50
 * Problem Set 4
 *
 * 1. Open file
 * 2. Update header info for outfile
 * 3. Read each scanline, pixel by pixel
 * 4. Resize horizontally
 * 5. Remember padding
 * 6. Resize vertically
 * 
 * Usage: ./resize n infile outfile
 * where n in integer is factor of resize.
 * size of outfile is multiple of n times of infile
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember n and filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];


    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

   // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // BITMAPFILEHEADER & BITMAPINFOHEADER change with factor of n
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biWidth = (n*bi.biWidth);
    bi.biHeight = (n*bi.biHeight);
    
    //determine for n factor, if new padding is require
    int newpadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biSizeImage = ((bi.biWidth * 3 + newpadding) * abs(bi.biHeight)); //last
    bf.bfSize = (bf.bfOffBits + bi.biSizeImage); // last

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        //check if vertical need to be multiple
        if ( i%n != 0 )
        {
             fseek(inptr, ((-3 * bi.biWidth/n) - padding) , SEEK_CUR);
        }
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            //check if RGBTRIPLE need to be multiple
            if  (j%n != 0)
                    {
                        fseek(inptr, -3, SEEK_CUR);
                    }
                    
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
      

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < newpadding; k++)
        {
            fputc(0x00, outptr);
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

/*OUTPUT
antw@Mac-mini c % clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow   resize.c  -lm -o resize 
antw@Mac-mini c % ./resize
Usage: ./resize n infile outfile
antw@Mac-mini c % ./resize 4 small.bmp large.bmp
antw@Mac-mini c % ls *.bmp                      
large.bmp	small.bmp
antw@Mac-mini c % xxd -c 12 -g 3 -s 54 small.bmp
antw@Mac-mini c % xxd -c 36 -g 3 -s 54 large.bmp
antw@Mac-mini c % xxd -c 20 -g 3 -s 54 medium.bmp
antw@Mac-mini c % man xxd
*/
