/**
 * initials.c
 * 2022 Feb 20, revised to move cs50 function to here.
 * 
 * a program that prompts user for their name
 * and then outputs their initials in uppercase with no spaces or periods.
 * Assume that the user's input will contain only letters (uppercase
 * and/or lowercase) plus spaces between words.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char* string;   /* from cs50.h */
string GetString(void); /* prototype */

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


#include <limits.h>
#include <stdlib.h>

/* from cs50.c */
string GetString(void)
{
    // growable buffer for chars
    string buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
            {
                capacity = 32;
            }
            else if (capacity <= (UINT_MAX / 2))
            {
                capacity *= 2;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            string temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    // minimize buffer
    string minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}

/*
antw@Mac-mini c % clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow    initials.c  -lm -o initials
antw@Mac-mini c % ./initials
Zamyla Chan
ZC
antw@Mac-mini c % ./initials
   robert  thomas bowden
RTB
antw@Mac-mini c % ./initials
 milo  banana 
MB

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
*/
