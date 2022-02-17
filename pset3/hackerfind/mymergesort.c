/**
 * mymergesort.c
 * : sort by split the array to half using recursive
 * : then marge the left and right of array, using void merge()
 * Oct20, 2015
 * use to test:    
 * printf("LeftLo %i | Md %i || RightLo %i | Hi %i", LeftLo, Md, RightLo, Hi);
 * printf(" TOP L tmp[%i] = %i\n", tindex-1, tmp[tindex-1] );  
 * string name2 = GetString(); printf(" | %s\n", name2);
 */


#include <stdio.h>
int Sorting(int values[], int Lo, int Hi);
void merge (int array[], int start, int LeftHi, int RightLo, int RightHi);


#define SIZE 10
int aarray[] = {22,11,66,99,77,  33,44,10,55,88, 02,13,56,76,98};
//int aarray[] = {11,22,44,66,88,   00,33,55,77,99, 02,13,56,76,98};
//int aarray[] = {55,66,77,88,99,  00,11,22,33,44, 02,13,56,76,98};

int main(void)
{
    int Lo = 0; int Md = (SIZE-1)/2; int Hi = SIZE-1;
    
    printf("\n  >> merging from array[%i] = %i, & from array[%i] = %i\n", Lo, aarray[Lo], Md+1, aarray[Md+1]); 

    printf(" array = ");
    for (int i =0; i <= Hi; i++) printf(":%i ", aarray[Lo+i] ); printf ("\n");
    
    // sorting
    Sorting(aarray, Lo, Hi);
        
    printf(" array = ");
    for (int i =0; i <= Hi; i++) printf(":%i ", aarray[Lo+i] ); printf ("\n");
    
}

// split to Left and Right, then merge
int Sorting(int values[], int Lo, int Hi)
{
// from mytest2.c
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

        // merge the two halves
        //printf("merge Lo:%i, Md:%i, Md+1:%i, Hi:%i\n",Lo, Md, Md +1, Hi );
        merge(values, Lo, Md, Md +1, Hi);         
        return 1;    
    }
}


// from mymerge.c
void merge (int array[], int start, int LeftHi, int RightLo, int RightHi)
{
    int LeftLo = start;
    int tindex = 0;
    int tmp[SIZE];

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
    
    // print ********
    printf("*merged =");
    for (int i =start; i <= RightHi; i++) printf(":%i ", array[i] ); printf ("\n");
}

/*
OUTPUT:
~/workspace/pset3/hackerfind $ ./mymergesort

  >> merging from array[0] = 22, & from array[5] = 33
 array = :22 :11 :66 :99 :77 :33 :44 :10 :55 :88 
*merged =:11 :22 
*merged =:11 :22 :66 
*merged =:77 :99 
*merged =:11 :22 :66 :77 :99 
*merged =:33 :44 
*merged =:10 :33 :44 
*merged =:55 :88 
*merged =:10 :33 :44 :55 :88 
*merged =:10 :11 :22 :33 :44 :55 :66 :77 :88 :99 
 array = :10 :11 :22 :33 :44 :55 :66 :77 :88 :99 
~/workspace/pset3/hackerfind $ 

valgrind:
==3924== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
