/* load
just load, copy from before u.5.c
20190928
*/
// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27 // 26 letters + apostrophes ??
// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;
// Represents a trie
node *root;

// my prototype
//bool scanline(int sc_low, int sc_max);


/***** ***** ***** load */
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int C_mallloc = 0;                                          // **** tobedel ****
    // Initialize trie
    root = malloc(sizeof(node));  C_mallloc++;                  // **** tobedel ****
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];  // 45+1

    // heap 808 bytes allocated
    node *temp = malloc(sizeof(node)); // memory allocate  224 (5128 - 4904)
    *temp = *root;

    //heap 1,032 bytes allocated for 'cat' , empty
    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)  // memory (5,128 - 1032) from emty text
    {
        // heap 5,128 bytes allocated
        node *ptr = root;

        int i = 0; while (word[i])                              // ver 20190928
        {
            // n - 97 integer of alphabet, which coressponding to children[n]
            int a = (int)word[i] - 97;
            if (a == -58) { a = 26;} //  apostrophes, 39,

            //printf("break \n"); return false; //break;
            // heap 5,128 bytes allocated
            if (!ptr->children[a])
            {
                // Allocate space for new node
                node *n = malloc(sizeof(node));
                // memory allocate  224 (5352 -5128) for 'c'
                // memory allocate  672 (224*3) (5800 - 5128) for 'cat'
                C_mallloc++;            // **** tobedel ****
                //printf("break \n"); return false; //break;  5,352 for 'c'
                if (!n) {return 1; }        // timing same, if remove
                *n = *temp; // copy the format only

                //ptr->is_word = true; // set this pointer to true (1) for every node reached
                ptr->children[a] = n;
            }

            ptr = ptr->children[a]; // next ptr

            i++ ;
        }

        // if at end of word, set is_word to true
        ptr->is_word = true;
    }

    free(temp);

    // Close dictionary
    fclose(file);

    printf("* Count malloc: %i \n", C_mallloc);            // **** tobedel ****
    printf ("total size of %i malloc node : %lu\n", C_mallloc, C_mallloc * sizeof(node));
    printf("sizeofnode : %lu\n", sizeof(node));
    printf ("total size in dcitionary node of 143091 words : %lu\n", 143091 * sizeof(node));
    printf ("total size in dcitionary node of 3 words : %lu\n", 3 * sizeof(node));
    //printf ("total size 224 * 143091 words * ?? : %d * ??\n", 224 * 143091);
    /*
    ~/work4/ $ ./l
    for dictionary/cat
     * Count malloc: 4
    total size of 4 malloc node : 896
    sizeofnode : 224
    total size in dcitionary node of 143091 words : 32052384
    total size in dcitionary node of 3 words : 672
    total size 224 * 143091 words : 32052384
    ==5000==
    ==5000== HEAP SUMMARY:
    ==5000==     in use at exit: 928 bytes in 5 blocks
    ==5000==   total heap usage: 8 allocs, 3 frees, 5,800 bytes allocated


    for dictionary/large
    * Count malloc: 367082
    total size of 367082 malloc node : 82226368
    sizeofnode : 224
    total size in dcitionary node of 143091 words : 32052384
    total size in dcitionary node of 3 words : 672
    total size 224 * 143091 words : 32052384
    ==4845==
    ==4845== HEAP SUMMARY:
    ==4845==     in use at exit: 82,226,400 bytes in 367,083 blocks
    ==4845==   total heap usage: 367,086 allocs, 3 frees, 82,231,272 bytes allocated
    ==4845==


    for dictionary/small // for 'cat' & 'catch'
    * Count malloc: 6
    total size of 6 malloc node : 1344
    sizeofnode : 224
    total size in dcitionary node of 143091 words : 32052384
    total size in dcitionary node of 3 words : 672
    total size 224 * 143091 words : 32052384
    ==843==
    ==843== HEAP SUMMARY:
    ==843==     in use at exit: 1,376 bytes in 7 blocks
    ==843==   total heap usage: 10 allocs, 3 frees, 6,248 bytes allocated


    */


    // Indicate success
    return true;

    //printf("break \n"); return false; //break;  5,352 for 'c'
    //
        //printf("break \n"); return false; //break;
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{ /*
    //bool scanning;
    //bool scanning = scanline(0,5);

    node *ml[46];           // memorise the address at this level
    int ma[46];             // memorise the alphabetic of that level

    node *ptr = root;       // copy pointer

    int mc = 0;             // levelth
    int a = 0;              // alpha position

    while (a < 27)
    {
        if (ptr->children[a] != NULL)
        {                   //printf("w lvl %i %c\n", mc,  97+a);// testing *
            ml[mc] = ptr;   // save the pointer at mc level
            ma[mc] = a;     // save the alpha position at mc level
                                                //printf("m%i ", mc);
            // point to the next children
            ptr = ptr->children[a]; //same as ptr = ml[mc]->children[ma[mc]];
            mc++;           // next deeper level
            a=0;            // start to scan at alpha 0
        }
        else
        {
            a++;                                // if the children null, move to next alpha

            while (a >= 27)
            {                                   //printf("N lvl %i %c\n", mc,  97+a); // testing *
                node *temp = ptr;
                mc = mc -1;                     // move back to the previous level
                if (mc < 0) { break; }          // if already at root level, break

                // copy pointer and alpha to pointer
                ptr = ml[mc];                   //printf("ml[%i]  |  ", mc); //previous , t
                ptr->children[ma[mc]] = NULL;   //printf("children[ma[%i] %c = null |  ", mc, ma[mc]+97 );

                if (temp != NULL)
                                                //printf("free ml[%i + 1] \n",mc);

                { free (temp); }

                a = ma[mc]+1;   // if a is 26, loop back
            }
        }
    }

    //return n;
    // for testing
    //printf("%i N:", ptr->is_word); for (int z = 0; z < N; z++) // 0 is false**** my test
    //{ if (ptr->children[z]) printf("%c ", 97+z); else printf(". ");  } printf("\n");
    free (root);
    //bool scanning = scanline(0,5);
*/
    return true;
    // valgrind error  for cat and catch, 3 block loss at malloc, u.c:353

}



// Default dictionary
#define DICTIONARY "dictionaries/cat"

int main(void)
{
    bool loaded = load(DICTIONARY);
    //bool scanning = scanline(0,50);

    bool unloaded = unload();
    //bool scanline(int sc_low, int sc_max)
    //bool scanning = scanline(0,50);
}

/*

valgrind --leak-check=full --show-leak-kinds=all ./u

total size of 1 malloc node : 224
==2281==
==2281== HEAP SUMMARY:
==2281==     in use at exit: 256 bytes in 2 blocks
==2281==   total heap usage: 5 allocs, 3 frees, 5,128 bytes allocated

remove node temp
==2863== HEAP SUMMARY:
==2863==     in use at exit: 32 bytes in 1 blocks
==2863==   total heap usage: 2 allocs, 1 frees, 256 bytes allocated

for 'cat' with full unload
==2916==     in use at exit: 32 bytes in 1 blocks
==2916==   total heap usage: 8 allocs, 7 frees, 5,800 bytes allocated
for 'cat' with NON unload
==3072==     in use at exit: 928 bytes in 5 blocks
==3072==   total heap usage: 8 allocs, 3 frees, 5,800 bytes allocated

*/