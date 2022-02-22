/** collatz.c
*   The Collatz Conjectual is applied to positive integers and
*   speculates that it is always possible to get "back to 1"" if you
*   follow these steps;
*   . If n is 1, stop. Otherwise, 
*   . if n is even, repeat this process on n/2. Otherwise,
*   . if n is odd, repeat this process on 3n + 1.
*
*   Demostrate Recursion
*/

#include <stdio.h>
#include <stdlib.h>

int collatz(int n);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./collatz n\n");
        return -1;
    }

    // remember number
    int number = atoi( argv[1] );

    printf ("\nCollatz steps: %i\n\n", collatz(number));
}


int collatz(int n)
{
    printf(" -> %i", n);

    // base case
    if (n == 1)
        return 0;
    
    // even numbers
    else if (( n % 2 ) == 0 )
        return 1 + collatz( n / 2 );

    // odd numbers
    else
        return 1 + collatz( 3 * n + 1 );
}

/*
antw@Mac-mini c % vi collatz.c
antw@Mac-mini c % make collatz
cc     collatz.c   -o collatz
antw@Mac-mini c % ./collatz 6 
 -> 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 8

antw@Mac-mini c % ./collatz 7
 -> 7 -> 22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 16

antw@Mac-mini c % vi collatz.c
antw@Mac-mini c % make collatz
cc     collatz.c   -o collatz
antw@Mac-mini c % ./collatz 4 
 -> 4 -> 2 -> 1
Collatz steps: 2

antw@Mac-mini c % ./collatz 2
 -> 2 -> 1
Collatz steps: 1

antw@Mac-mini c % ./collatz 6
 -> 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 8

antw@Mac-mini c % ./collatz 7
 -> 7 -> 22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 16

antw@Mac-mini c % ./collatz 50
 -> 50 -> 25 -> 76 -> 38 -> 19 -> 58 -> 29 -> 88 -> 44 -> 22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 24

antw@Mac-mini c % 
*/
