/**
 * find.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */
       
#include <cs50.h>
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
        printf("\nhaystack[%i] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);
    

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
~/workspace/pset3/find $ make
clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm
clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c
~/workspace/pset3/find $ ./find
Usage: ./find needle
~/workspace/pset3/find $ ./find 13

haystack[0] = 20

haystack[1] = (ctrl-d)

Didn't find needle in haystack.

~/workspace/pset3/find $ ./generate 1000 | ./find 42
...
haystack[999] = 
haystack[1000] = 

Didn't find needle in haystack.

...
Alternatively, you can "redirect" generate's output to a file with a command like the below.

./generate 1000 > numbers.txt
You can then redirect that file’s contents as input to find with the command below.

./find 42 < numbers.txt

note that main in find.c is written in such a way that find returns 0 if the needle is found, else it returns 1. You can check the so-called "exit code" with which main returns by executing

echo $?
*/