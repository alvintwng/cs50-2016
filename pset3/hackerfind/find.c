/**
 * find.c
 *
 * 2022 Feb 26, revised to added in cs50 dir & Makefile
 * Oct 21, 2015
 * Computer Science 50
 * Problem Set 3
 * 
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *        ./generate 5000 10 | ./find 12348
 *        ./generate 1000 50 | ./find 127
 *        ./generate 10 50 | ./find 52692
 * where needle is the value to find in a haystack of values
 */
       
#include "../cs50/cs50.h"
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        // printf("\nhaystack[%d] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // BUBBLE sort the haystack
    sort(haystack, size);
    
    /*/ **** prints test the whole list
    for (int i=0; i<=size; i++)
    {
        printf("haystack[%i] = %i\n", i, haystack[i] );
    }
    /*/

    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
}

/*OUTPUT
antw@Mac-mini hackerfind % make clean
rm -f *.o a.out core find generate
antw@Mac-mini hackerfind % make
clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c ../cs50/cs50.c -lm
clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c
antw@Mac-mini hackerfind % ./generate 5000 10 | ./find 12348

pre mergesort: values[0] = 57596 ... values[4999] = 41803
Done sorted  : values[0] = 14     ... values[4999] = 65524

Found needle in haystack!

antw@Mac-mini hackerfind % 
antw@Mac-mini hackerfind % ls *.dSYM
find.dSYM:
generate.dSYM:
antw@Mac-mini hackerfind % rm -Rf *.dSYM
*/
