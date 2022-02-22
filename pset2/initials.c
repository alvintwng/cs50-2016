/* initials.c
 * 2022 Feb 20, revised to move cs50 function to here.
 *
 * a program that prompts user for their name
 * and then outputs their initials in uppercase with no spaces or periods.
 * Assume that the user's input will contain only letters (uppercase
 * and/or lowercase) plus single spaces between words.
 *
 * to check the correctness:
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char* string;   /* from cs50.h */
string GetString(void); /* prototype */

int main(void)
{
    //get line of text
    printf("Name please: ");    
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
antw@Mac-mini c % make initials
cc     initials.c   -o initials
antw@Mac-mini c % ./initials
Name please: Zamyla Chan
ZC
antw@Mac-mini c % ./initials
Name please: robert thomas bowden
RTB
*/
