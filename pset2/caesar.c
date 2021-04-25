/**
 * caesar.c
 * encrypts messages using Caesar's cipher.
 * to accept a single command-line argument: a non-negative integer.
 * otherwise return a value of 1.
 * Prompt the users for a string of plaintext and 
 * output the by k positions, non-alphabetical will be output unchanged.
 * after all ciphertext, will exit with return 0.
 *
 * check the correstness via
 * check50 2015.fall.pset2.caesar caesar.c
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


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

/*OUTPUT
~/workspace/pset2 $ ./caesar

~/workspace/pset2 $ ./caesar 13
Be sure to drink your Ovaltine!
Or fher gb qevax lbhe Binygvar!
~/workspace/pset2 $ 
*/
