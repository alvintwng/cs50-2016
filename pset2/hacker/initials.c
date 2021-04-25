/**
 * initials.c
 * a program that prompts user for their name
 * and then outputs their initials in uppercase with no spaces or periods.
 * Assume that the user's input will contain only letters (uppercase
 * and/or lowercase) plus spaces between words.
 *
 * to check the correctness:
 * check50 2014.fall.hacker2.initials initials.c
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
        // print to Uppercase of i char
        if (isalpha(s[0]))
        {
        printf ("%c", toupper(s[0]));
        }
        
        // check letter each
        for (int i = 1, n = strlen(s); i < n ; i++)
        {
            // check for current is alpha and previous is space
            if ( isspace(s[i-1]) && isalpha(s[i]))
            {
                // print to Uppercase of i char
                printf ("%c", toupper(s[i]));
            }
        }
        printf("\n");
    }
}

/*
~/workspace/pset2/hacker $ make initials
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow    initials.c  -lcs50 -lm -o initials
~/workspace/pset2/hacker $ ./initials
Zamyla Chan
ZC
~/workspace/pset2/hacker $ ./initials
   robert  thomas bowden
RTB
~/workspace/pset2/hacker $ check50 2015.fall.hacker2.initials initials.c
:) initials.c exists
:) initials.c compiles
:) outputs "MB" for "Milo Banana"
:) outputs "MB" for "milo banana"
:) outputs "MB" for " milo  banana "
:) outputs "MB" for "  milo banana  "
:) outputs "RTB" for "   robert   thomas bowden"
:) outputs "RTB" for "Robert Thomas Bowden"
:) outputs "R" for "ROB"
:) outputs "RTB" for "Robert thomas Bowden"
https://sandbox.cs50.net/checks/65c0441d51534633bc99ada6ed141f55
~/workspace/pset2/hacker $ 
*/