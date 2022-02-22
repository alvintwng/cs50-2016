/** CS50 Problem set wk1
  * mario.c
  * 2015 sep 14, ngtw
  * 2022 Feb 20, revised to removed cs50.h.  
  */

#include <stdio.h>

int main(void)
{
// Prompt and validate user input
// non-negative integer no greater than 23

    // using do-while Loop

    int height;
    do
    {
        printf("height: ");
        scanf("%d", &height);   // was height = GetInt();  
    }
    // height less 1 or n more than 23
    while ( height< 0 || height > 23 );

// Draw the Pyramid

//    printf("height = %i\n", height);
    
    // using for loop
    for (int loop=0; loop<height; loop++)
        {
        
    // Draw the LEFT half-pyramid
     
        // print spaces
            for (int spac=0; spac<(height-loop-1); spac++)
                {
                    printf(" ");
                }
        
        // print hashes loop
            for (int hash=0; hash<(loop+1); hash++)
                {
                    printf("#");
                }
    // Draw SPACEs in between
            printf ("  ");
                      
    // Draw the RIGHT half-pyramid  
        // print hashes loop
            for (int hash=0; hash<(loop+1); hash++)
                {
                    printf("#");
                }
                   
                      
        // print new line./mario
        printf("\n");
        }
}

/*  OUTPUT
antw@Mac-mini c % gcc -g -Wall mario.c -o mario
antw@Mac-mini c % ./mario
height: 4
   #  #
  ##  ##
 ###  ###
####  ####

:) mario.c exists
:) mario.c compiles
:) rejects a height of -1
:) handles a height of 0 correctly
:) handles a height of 1 correctly
:) handles a height of 2 correctly
:) handles a height of 23 correctly
:) rejects a height of 24
??? :) rejects a non-numeric height of "foo"
??? :) rejects a non-numeric height of ""
*/
