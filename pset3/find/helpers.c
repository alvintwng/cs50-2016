/**
 * helpers.c
 *
 * Computer Science 50
 * 2022 Feb 26, revised to added in cs50 dir & Makefile 
 *
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
/**
 * use wuth generate.c find.c helpers.c
 * Usage: ./find needle
 * Usage: ./generate 100 5 | ./find 12345
 * found: ./generate 1000 50 | ./find 127
 * where needle is the value to find in a haystack of values
 */
       
#include "../cs50/cs50.h"

#include "helpers.h"

#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //implement a searching algorithm
    // ** BINARY SEARCH **
    int LOW = 0, MID= n/2, HIGH= n;
    
    do {
        // check if needle == LOW, MID, HIGH, return TRUE
        if (value == values[LOW] || value == values[MID] || value == values[HIGH])
        {
            return true;
        }
        
        if (value < values[MID])
        {
            // if needle at LEFT half convert Mid to HIGH
            HIGH = MID;
            MID = (LOW + HIGH) /2;
        }
        else
        {
            // or RIGHT half convert MId to LOWER
            LOW = MID;
            MID = (LOW + HIGH) /2;
        }
        
        // check if HIGH - LOW < 2, return FALSE
    } while (HIGH - LOW > 1);
        
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //implement an O(n^2) sorting algorithm
    // ** INSERTION SORT **
        // looping unsort array, left to right (i)
        int i,j;
        for (i = 1; i < (n); i++)
        {
            // identfy left unsorted as Insertion Element, and set index position (j)
            int element = values[i];
            j = i;
            
            // Shift Element to left untill less than sorted array. 
            //left sorted array is greater than Element, and not zero index
            while (j > 0 && values[j-1] > element)
            {
                //  than shift/save left array to right array
                values[j] = values[j-1];
                j = j-1;
            }
            // if left sorted is less than element, than Insert element into array [j]
            values[j] = element;
            
        }
        
     return;       
}

/*OUTPUT
antw@Mac-mini find % ./generate 1000 50 | ./find 127
...

Found needle in haystack!

antw@Mac-mini find % 
*/
