/* vigenere.c 
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
 * 
 * checking the correstnes:
 * check50 2015.fall.pset2.vigenere vigenere.c
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

/*OUTPUT
~/workspace/pset2 $ ./vigenere bacon
Meet me at the park at eleven am
Negh zf av huf pcfx bt gzrwep oz
*/