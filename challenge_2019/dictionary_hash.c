// Implements a dictionary's functionality
// cs50 2016 pset5, dated July 2016
// speller_hash

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASHSIZE 456976

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

/*/ Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node; */


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * link list node
 */
typedef struct node
{
    char* word;
    struct node* next;
}
node;

/**
 * struct for hash bucket
 */
typedef struct
{
    struct node* next;
}
hashnode;

/**
 * call for hash value of word
 */
int hash_function(const char* key);

/**
 * link list for hash table
 */
void linklist(node* thisnode);



FILE* fp; //file declare
node* first = NULL;
hashnode hash[HASHSIZE];
int dictionary_word_counter = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //To convert const char* to char*
    char* w = malloc((strlen(word) + 1) * sizeof(char));

    // copy string
    for (int i = 0, n = strlen(word); i <= n; i++)
    {
        //convert to lower case word
        if(isupper(word[i]))
        {
            w[i] = tolower(word[i]);
        }
        else
        {
            w[i] = word[i];
        }
    }

    //start from hash# buckets
    int hashno = hash_function(w);

    if (hash[hashno].next == NULL)
    {
        free(w); //free malloc
        return false;
    }
    else
    {
        // get text's first node from hash
        node* ptr = hash[hashno].next;

        // search for word thru link-list
        while (ptr != NULL)
        {
            //to compare word
            if (strcmp(ptr->word, w) == 0)
            {
                free(w); //free malloc
                return true;
            }
            ptr = ptr->next; //repeat
        }
        free(w);  //free malloc
        return false;
    }
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //try to open text
    fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open text.\n");
    }

  while(true)
  {
    // try to instantiate node for word !1! new node created
    node* newptr = malloc(sizeof(node));

    newptr->next = NULL;

    // try to instantiate word          !3! new node set 'word'
    newptr->word = malloc(LENGTH +1);

    // try to initialize word           !4! new node input value
    if (fscanf(fp, "%s", newptr->word) == EOF)
    {
        free(newptr->word);
        free(newptr);
        break; // to break the while-loop
    }


    //identify hash#                    !6! Hash for new node
    int hashno = hash_function(newptr->word);

    if (hash[hashno].next == NULL)  //  !7! new node home
    {
        hash[hashno].next = newptr;
    }

    else
    {
        newptr->next = hash[hashno].next; //!8! if not next add for new node
        hash[hashno].next = newptr;
    }

    ///counter for size ///
    dictionary_word_counter ++;

  }
    // close text
    fclose(fp);

    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dictionary_word_counter != 0)
    {
        return dictionary_word_counter;
    }
    else
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int hi = 0; hi < HASHSIZE; hi++)
    {
        if (hash[hi].next != NULL)
        {
            first = hash[hi].next; // free nodes
            while (first != NULL)
            {
                node* predptr = first;
                first = first->next;
                if (predptr->word != NULL)
                {
                    free(predptr->word);
                }

                free(predptr);
            }
        }
    }
    return true;
}



/**
 * call for hash value of word
 */
int hash_function(const char* key)
{
    int hashnumber;
    if (tolower(key[1]) != 0)
    {
        if (tolower(key[2]) != 0)
        {
            if (tolower(key[3]) != 0)
            {
            hashnumber = ( tolower(key[0])*17576 +tolower(key[1])*676 +tolower(key[2])*26 + tolower(key[3]) )% HASHSIZE; //for HAZESIZE 456976
            return hashnumber;
            }

        hashnumber = ( tolower(key[0])*17576 +tolower(key[1])*676 +tolower(key[2])*26 )% HASHSIZE; //for HAZESIZE 456976, 3 char
        return hashnumber;
        }
    }

    hashnumber = ( tolower(key[0])*17576 +tolower(key[1])*676                     )% HASHSIZE; //for HAZESIZE 456976 , 2 char

    return hashnumber;
}


/**
 * link list for hash table
 * node: preptr, first
 */
void linklist(node* thisnode)
{
    node* predptr = first;
    while(true)
    {
        //check for insertion at tail
        if(predptr->next == NULL)
        {
            predptr->next = thisnode;
            break;
        }

        //update pointer
        predptr = predptr->next;
    }
}