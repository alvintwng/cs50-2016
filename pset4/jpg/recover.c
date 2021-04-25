/**
 * recover.c, with card.raw
 * dated: June 05, 2016
 * 
 * open "card.raw" file
 * FILE *fopen(const char *filename, const char *mode);
 * 
 * fread file: 1*sizeof(longb), 128, & EOF
 * check start of jpeg, where start block of jpeg photo: 
 * 1stbyte FF; 2nd is D8; 3rd is FF; 4th is E?;
 * 
 * print photo# and bytes
 * 
 * eof and closed
 * 
 * test: check50 2015.fall.pset4.recover recover.c
 * checked used:  xxd -l 120 -c 12 000.jpg
 */

#include <stdio.h>
#include <stdlib.h>


int longb;

    
int main(void)
{
    int buff[128]; //block of 512bytes, 4*128
    int photosn = -1;  //photo #,  was npts
    int jpeg0 = 0xE0FFD8FF;  //where start block of jpeg photo, FF, D8, FF, F?
    int jpeg1 = 0xE1FFD8FF;
    int jpeg2 = 0xE2FFD8FF;
    int jpeg3 = 0xE3FFD8FF;
    int jpeg4 = 0xE4FFD8FF;
    int jpeg5 = 0xE5FFD8FF;
    int jpeg6 = 0xE6FFD8FF;
    int jpeg7 = 0xE7FFD8FF;
    int jpeg8 = 0xE8FFD8FF;
    int jpeg9 = 0xE9FFD8FF;
    int jpega = 0xEAFFD8FF;
    int jpegb = 0xEBFFD8FF;
    int jpegc = 0xECFFD8FF;
    int jpegd = 0xEDFFD8FF;
    int jpege = 0xEEFFD8FF;
    int jpegf = 0xEFFFD8FF;
    

    // open card file 
    FILE* file = fopen("card.raw", "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 1;
    }
    
    FILE* img = NULL;
    
    // fread file & check EOF
    while ((fread (&buff, 1*sizeof(longb), 128, file) ) == 128) //if not EOF
    {
        if (buff[0] == jpeg0 || buff[0] == jpeg1 || buff[0] == jpeg2 || buff[0] == jpeg3 || buff[0] == jpeg4 || buff[0] == jpeg5 || buff[0] == jpeg6 || buff[0] == jpeg7 || buff[0] == jpeg8 || buff[0] == jpeg9 || buff[0] == jpega || buff[0] == jpegb || buff[0] == jpegc || buff[0] == jpegd || buff[0] == jpege || buff[0] == jpegf  )
        //check start of jpeg
            {
                if (img != NULL)
                { fclose(img); }
                
                photosn++; //next photo no
                
                //generate new file name
                char jn[8];
                sprintf (jn, "%03d.jpg", photosn);
                char* title = jn;

                img = fopen(title, "a");
            }
        
        if (photosn > -1) // if photosn = # for debug
        {
            fwrite (&buff, 1*sizeof(longb), 128, img);
        }     
        
    }
    if (img != NULL)
    { fclose(img); }

    // close infile
    fclose(file);
    return 0;

}

/*
~/workspace/pset4/jpg $ make recover
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow    recover.c  -lcs50 -lm -o recover
~/workspace/pset4/jpg $ ./recover
~/workspace/pset4/jpg $ ls
000.jpg  006.jpg  012.jpg  018.jpg  024.jpg  030.jpg  036.jpg  042.jpg  048.jpg
001.jpg  007.jpg  013.jpg  019.jpg  025.jpg  031.jpg  037.jpg  043.jpg  049.jpg
002.jpg  008.jpg  014.jpg  020.jpg  026.jpg  032.jpg  038.jpg  044.jpg  card.raw
003.jpg  009.jpg  015.jpg  021.jpg  027.jpg  033.jpg  039.jpg  045.jpg  recover*
004.jpg  010.jpg  016.jpg  022.jpg  028.jpg  034.jpg  040.jpg  046.jpg  recover.c
005.jpg  011.jpg  017.jpg  023.jpg  029.jpg  035.jpg  041.jpg  047.jpg
~/workspace/pset4/jpg $ check50 2015.fall.pset4.recover recover.c
:) recover.c exists
:) recover.c compiles
:) recovers 000.jpg correctly
:) recovers middle files correctly
:) recovers last file correctly
https://sandbox.cs50.net/checks/b73ebd3504e643518df423060cb2cbc5
~/workspace/pset4/jpg $ 
*/