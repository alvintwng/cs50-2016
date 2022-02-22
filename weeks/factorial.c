/**   factorial.c
*     cs50 Week 4 2016
*     2022 Feb 22, revised
*     
*     Recursive on Factorial
*     with command-line argument
*     convert char to integer
*/


#include <stdio.h>

int factorial(int n);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if( argc != 2 )
    {
        printf("Usage: ./factorial n\n");
        return 1;
    }

    // convert char to integer, only single digit!
    int n = *argv[1] - '0';

    // n not negative
    if ( n < 2 || n > 9 )
    {
      printf(" n in range of 2 to 9 \n");
      return 1;
    }

    // print out
    printf("  n = %i\n", n);
    printf("  n! = n * (n-1)!\n");
    printf("  Factorial of %i = %i\n", n, factorial(n));
}


/**
*   function for factorial
**/
int factorial(int n)
{
    printf("  %i! = %i * %i!\n",n,n,n-1);
    if(n == 1)
    {
        return 1;
    }

    return n*factorial(n-1);
}

/*
antw@Mac-mini c % make factorial
cc     factorial.c   -o factorial
antw@Mac-mini c % ./factorial 3
  n = 3
  n! = n * (n-1)!
  3! = 3 * 2!
  2! = 2 * 1!
  1! = 1 * 0!
  Factorial of 3 = 6
*/
