/* vigenere.c 
 * 2022 Feb 22, revised to move cs50 function to here.
 *
 * encrypts messages using Vigenere's cipher
 * 
 * to accept a single command-line argument: keyword, k,
 * composed alphabetical characters.
 * otherwise return a value of 1.
 *  
 * Prompt the users for a string of plaintext,p ,and 
 * encrypt according to Vigenere's cipher with l,
 * non-alphabetical will be output unchanged.
 * after all ciphertext, will exit with return 0.
 *
 * Keyword, k: A or a = 0; ...;  Z or z = 25 
 * jth to k; ith to p; jth of k will advance to next alphabetical of p only.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char* string;   /* from cs50.h */
string GetString(void); /* prototype */

int main( int argc, string argv[])
{
    // check on the 2nd string from prompt, otherwise re-prompt
    if (argc == 2)
    {
        //init keyword length and array
        int m = strlen(argv[1]);
        int key[strlen(argv[1])];

        // convert to uppercase, and less 65 to digit
        for (int j=0; j<m; j++)
        {
            // checked if alphabetical, otherwise return 1
            if (isalpha(argv[1][j]))
            {
                key[j] = toupper(argv[1][j]) - 65;
            }
            else
            {
                printf ("\n");
                return 1;
            }
                
        } 


        // get plain text
        string s = GetString ();

        if (s != NULL)
        {
            for (int ctr =0, i = 0, n = strlen(s); i <n; i++)
            {
                // encrypt if 'a' to 'z'
                if ( islower (s[i]))
                {
                    printf ("%c", (((s[i]+key[ctr])-97)%26)+97);
                    
                    // next keyword
                    ctr = (ctr + 1)%m;
                }
                
                // encrypt if 'A' to 'Z'
                else if ( isupper (s[i]))
                {
                    printf ("%c", (((s[i]+key[ctr])-65)%26)+65);
                    
                    // next keyword
                    ctr = (ctr + 1)%m;
                }
                
                // just print if not any alphabet
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

/*OUTPUT
antw@Mac-mini c % vi vigenere.c
antw@Mac-mini c % clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow   vigenere.c  -lm -o vigenere
antw@Mac-mini c % ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
*/
