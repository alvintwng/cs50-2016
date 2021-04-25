/** CS50 Problem set wk1
  * mario.c
  * 2015 sep 14, ngtw
  * tested ok thru:
  * check50 2014.fall.hacker1.mario mario.c
  */

#include <cs50.h>
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
        height = GetInt();  
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
    
/*OUTPUT
~/workspace/pset1/hacker $ ./mario
height: 4
   #  #
  ##  ##
 ###  ###
####  ####
~/workspace/pset1/hacker $ check50 2015.fall.hacker1.mario mario.c
:) mario.c exists
:) mario.c compiles
:) rejects a height of -1
:) handles a height of 0 correctly
:) handles a height of 1 correctly
:) handles a height of 2 correctly
:) handles a height of 23 correctly
:) rejects a height of 24
:) rejects a non-numeric height of "foo"
:) rejects a non-numeric height of ""
https://sandbox.cs50.net/checks/162babf5111e4463ae3a9d28b47da181
~/workspace/pset1/hacker $ 
*/