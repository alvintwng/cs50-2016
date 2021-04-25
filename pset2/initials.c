/* initials.c
 * 
 * a program that prompts user for their name
 * and then outputs their initials in uppercase with no spaces or periods.
 * Assume that the user's input will contain only letters (uppercase
 * and/or lowercase) plus single spaces between words.
 *
 * to check the correctness:
 * check50 2015.fall.pset2.initials initials.c
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get line of text
    string s = GetString();

    //error checking
    if ( s != NULL)
    {
        // check letter each
        for (int i = 0, n = strlen(s); i < n ; i++)
        {
            // check for previous chars, eg spaces, not a to Z
            if (toupper (s[i-1]) < 'A' || toupper (s[i-1]) > 'Z')
            {
                // print to Uppercase of i char
                printf ("%c", toupper(s[i]));
            }
        }
        printf("\n");
    }
    
}
/*OUTPUT
~/workspace/pset2 $ ./initials
Zamyla Chan
ZC
~/workspace/pset2 $ ./initials
robert thomas bowden
RTB
*/