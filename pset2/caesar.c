/**
 * caesar.c
 * 2022 Feb 22, revised to move cs50 function to here.
 * encrypts messages using Caesar's cipher.
 * to accept a single command-line argument: a non-negative integer.
 * otherwise return a value of 1.
 * Prompt the users for a string of plaintext and 
 * output the by k positions, non-alphabetical will be output unchanged.
 * after all ciphertext, will exit with return 0.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef char* string;   /* from cs50.h */
string GetString(void); /* prototype */

int main( int argc, string argv[])
{
    // check on the 2nd string from prompt, otherwise re-prompt
    if (argc == 2)
    {
        //convert input number into int
        int k = atoi(argv[1]);

        // get plain text
        string s = GetString ();

        if (s != NULL)
        {
            for (int i = 0, n = strlen(s); i <n; i++)
            {
                // encrypt if 'a' to 'z'
                if ( islower (s[i]))
                {
                    printf ("%c", (((s[i]+k)-96)%26)+96);
                }
                else if ( isupper (s[i]))
                {
                    printf ("%c", (((s[i]+k)-64)%26)+64);
                }
                else
                {
                    printf ("%c", s[i]);
                }
            }
            printf ("\n");
        }
        return 0;
    }
    else
    {
        printf ("\n");
        return 1;
    }
}


#include <limits.h>

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


/*OUTPUT
antw@Mac-mini c % clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow   caesar.c  -lm -o caesar
antw@Mac-mini c % ./caesar 13
Be sure to drink your Ovaltine!
Or fher gb qevax lbhe Binygvar!
*/
