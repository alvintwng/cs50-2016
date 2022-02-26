/**
 * generate.c
 * 2022 Feb 26, revised to added in cs50 dir & Makefile 
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include "../cs50/cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    //check for 2 or 3 words at command-line argument, otherwise redo again
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    //convert the 1st command-line (2nd word) into integer
    int n = atoi(argv[1]);

    //if 3 words command-line argument, using seed to generate random
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    //to print out generated random integer, drand48 * 65536
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

/*OUTPUT
antw@Mac-mini find % make generate
clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c
antw@Mac-mini find % ./generate    
Usage: generate n [s]
antw@Mac-mini find % ./generate 10 0
11195
49145
6315
57046
37834
51498
45363
24167
57272
48830
antw@Mac-mini find %
*/
