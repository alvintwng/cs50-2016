/**
 * helpers.c
 * Oct 21, 2015
 * Computer Science 50
 * Problem Set 3
 * Helper functions for Problem Set 3.
 * use: ./generate 5000 10 | ./find 12348
 *      ./generate 1000 50 | ./find 127
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    //implement a searching algorithm
    // Binary Search
    int LOW = 0, MID= n/2, HIGH= n;
    
    do {
        // check if needle == LOW, MID, HIGH, return TRUE
        if (value == array[LOW] || value == array[MID] || value == array[HIGH])
        {
            return true;
        }
        
        if (value < array[MID])
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

/*{
    //implement a searching algorithm
    //  ** Linear Search **
    for (int i = 0; i < n; i++)
    {
        if (value == array[i])
        {
            return true;
        }    
    }
    
    return false;
}
*/
  // test with ./generate 10 5 | ./find 16834
  //           ./generate 1000 50 | ./find 127


/**
 * Sorts array of n values.
 * link to void Sorting() , and void merge()
 */
void sort(int values[], int n)
{
    // **** MERGE SORT  ***
    // void sort(int values[], int n)
    // On input of n elements
        // if n <2, return
        // else
            // sort left half of elements
            // sort right half of elements
            // merge sorted halves
            
    // ***************************        
    /**
    * copy and reference from mymergesort.c 
    */            
    int Lo = 0; int Hi = n-1;
        printf("pre mergesort: values[%i] = %i ... values[%i] = %i\n", Lo, values[Lo], Hi, values[Hi] ); 
    
    // sorting
    Sorting(values, Lo, Hi);    
        printf("Done sorted  : values[%i] = %i     ... values[%i] = %i\n", Lo, values[Lo], Hi, values[Hi] );  
            
    // *************************** 
    // implement an O(n) sorting algorithm
    /*/ **** BUBBLE SORT *** 
    int swapped;
    do
    {
        swapped = true;
        
        for (int i = 0; i < n-1; i++)
        {
            if (values[i] > values[i+1])
            {
                // do a swap;
                int tmp = values[i+1];
                values[i+1] = values[i];
                values[i] = tmp;
                swapped = false;
            }    
        }
    }
    while (swapped != true);
    
    return;
    
    */
    
}

/**
 * split to Left and Right, then use void merge()
 * copy from mymergesort.c
 * reference mytest2.c
 */
int Sorting(int values[], int Lo, int Hi)
{
    if (Hi == Lo)
    {
        return 0;
    }

    else
    {
        int Md = (Hi + Lo)/2;

        //sort Left side
        Sorting(values, Lo, Md);

        //sort Right side
        Sorting(values, Md+1, Hi);

            // **** PRINT TO TEST
            //printf("merge Lo:%i, Md:%i, Md+1:%i, Hi:%i ::",Lo, Md, Md +1, Hi );
            //printf(".");
       
        // merge the two halves
        merge(values, Lo, Md, Md +1, Hi);         
        return 1;    
    }
}


/** 
 * copy from mymergesort.c
 * marge the left and right of array
 *
 * run from void Sorting( ... )
 */
void merge (int array[], int start, int LeftHi, int RightLo, int RightHi)
{
    int LeftLo = start;
    int tindex = 0;
    int tmp[RightHi - start];

    if (array == NULL) { return;}

    while ( (LeftLo <= LeftHi) || (RightLo <= RightHi) )
    {
        //compare the values of LeftLo & RightLo, and out into tmp
        if (LeftLo <= LeftHi)
        {
            if ( array[LeftLo] < array[RightLo] )
            {
                tmp[tindex] = array[LeftLo];
                tindex ++;
                LeftLo ++;
            }
        }
        else
        {
            tmp[tindex] = array[RightLo];
            tindex ++;
            RightLo ++;
        }
      

        if (RightLo <= RightHi)
        {
            if ( array[LeftLo] >= array[RightLo] )
            {
                tmp[tindex] = array[RightLo];
                tindex ++;
                RightLo ++;
            }
        }
        else
        {
            tmp[tindex] = array[LeftLo];
            tindex ++;
            LeftLo ++;
        }
    }

    //cash in the tmp to array!
    for (int i =0; i <= (RightHi-start); i++)
    {
        array[start+i] = tmp[i];
    }
        //** PRINTING FOR TEST **
        //or printf("*merged =");
        //for (int i =start; i <= RightHi; i++) printf(":%i ", array[i] ); printf ("\n");
}

/*
OUTPUT:
jharvard@appliance (~/Dropbox/hacker3/find): ./generate 50000 10 | ./find 42346

pre mergesort: values[0] = 57596 ... values[49999] = 9901
Done sorted  : values[0] = 1     ... values[49999] = 65534

Found needle in haystack!

*/