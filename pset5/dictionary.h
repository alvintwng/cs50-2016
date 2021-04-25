/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASHSIZE 456976

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


#endif // DICTIONARY_H

/* reference

Usage: speller [dictionary] text
ex: ./speller texts/ralph.txt
ex: ./speller dictionaries/small texts/ralph.txt
ex: ./speller texts/pneumonoultramicroscopicsilicovolcanoconiosis.txt

~cs50/pset5/speller texts/austinpowers.txt > staff.txt
diff -y student.txt staff.txt

check50 2015.fall.pset5.speller dictionary.c dictionary.h Makefile


./speller texts/austinpowers.txt
WORDS MISSPELLED:     644
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        19190
TIME IN load:         0.03
TIME IN check:        0.12
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.16

 zero misspelled
./speller texts/daffodils.txt
WORDS MISSPELLED:     0
TIME IN TOTAL:        0.05

 minimum words, 20
./speller texts/ralph.txt
WORDS IN TEXT:        20
TIME IN TOTAL:        0.04


 max missppelled, 45,691
./speller texts/shakespeare.txt
WORDS MISSPELLED:     45691
TIME IN TOTAL:        0.91


 max words, 1,150,970
./speller texts/holmes.txt
WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970
TIME IN load:         0.04
TIME IN check:        8.72
TIME IN size:         0.00
TIME IN unload:       0.00
TIME IN TOTAL:        8.77
staff:
TIME IN TOTAL:        0.96


~cs50/pset5/speller texts/holmes.txt > staff.txt
./speller texts/holmes.txt > student.txt
diff -y student.txt staff.txt

WORDS MISSPELLED:     17845                                     WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091                                    WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970                                   WORDS IN TEXT:        1150970
TIME IN load:         0.04                                    | TIME IN load:         0.03
TIME IN check:        7.84                                    | TIME IN check:        0.65
TIME IN size:         0.00                                      TIME IN size:         0.00
TIME IN unload:       0.00                                    | TIME IN unload:       0.01
TIME IN TOTAL:        7.88                                    | TIME IN TOTAL:        0.69

2016Jul01 after HASHSIZE 17576, and hash 3letters
./speller texts/holmes.txt > student.txt
diff -y student.txt staff.txt

WORDS MISSPELLED:     17845                                     WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091                                    WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970                                   WORDS IN TEXT:        1150970
TIME IN load:         0.03                                      TIME IN load:         0.03
TIME IN check:        1.54                                    | TIME IN check:        0.65
TIME IN size:         0.00                                      TIME IN size:         0.00
TIME IN unload:       0.01                                      TIME IN unload:       0.01
TIME IN TOTAL:        1.58                                    | TIME IN TOTAL:        0.69



2016 Jul01 11:00am: increased the Hash of 4 letters and size
~/workspace/pset5 $ ./speller texts/holmes.txt > student.txt
~/workspace/pset5 $ ~cs50/pset5/speller texts/holmes.txt > staff.txt
~/workspace/pset5 $ diff -y student.txt staff.txt
WORDS MISSPELLED:     17845                                     WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091                                    WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970                                   WORDS IN TEXT:        1150970
TIME IN load:         0.04                                    | TIME IN load:         0.02
TIME IN check:        0.73                                    | TIME IN check:        0.61
TIME IN size:         0.00                                      TIME IN size:         0.00
TIME IN unload:       0.01                                      TIME IN unload:       0.01
TIME IN TOTAL:        0.77                                    | TIME IN TOTAL:        0.64

2016Jul01 10:50am: changed hash_function, n valgrind error free
~/workspace/pset5 $ ./speller texts/holmes.txt > student.txt
~/workspace/pset5 $ ~cs50/pset5/speller texts/holmes.txt > staff.txt
~/workspace/pset5 $ diff -y student.txt staff.txt
WORDS MISSPELLED:     17845                                     WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091                                    WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970                                   WORDS IN TEXT:        1150970
TIME IN load:         0.04                                      TIME IN load:         0.04
TIME IN check:        0.89                                    | TIME IN check:        0.73
TIME IN size:         0.00                                      TIME IN size:         0.00
TIME IN unload:       0.02                                    | TIME IN unload:       0.01
TIME IN TOTAL:        0.94                                    | TIME IN TOTAL:        0.78

~/workspace/pset5 $ 


~/workspace/pset5 $ check50 2015.fall.pset5.speller dictionary.c dictionary.h Makefile
:) dictionary.c, dictionary.h, Makefile exist
:) speller compiles
:) handles most basic words properly
:) handles min length (1-char) words
:) handles max length (45-char) words
:) spell-checking is case-insensitive
:) handles possessives properly
:) handles substrings properly
https://sandbox.cs50.net/checks/13fc53a1b15b4aaa92e7734738ced037
~/workspace/pset5 $ 

valgrind ./speller texts/holmes.txt
==3143== HEAP SUMMARY:
==3143==     in use at exit: 0 bytes in 0 blocks
==3143==   total heap usage: 1,437,156 allocs, 1,437,156 frees, 15,095,075 bytes allocated
==3143== 
==3143== All heap blocks were freed -- no leaks are possible
==3143== 
==3143== For counts of detected and suppressed errors, rerun with: -v
==3143== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
~/workspace/pset5 $ 


2016Jul03
~/workspace/pset5 $ zip -r pset5.zip *.c *.h questions.txt Makefile
  adding: dictionary.c (deflated 68%)
  adding: speller.c (deflated 70%)
  adding: dictionary.h (deflated 56%)
  adding: questions.txt (deflated 52%)
  adding: Makefile (deflated 41%)
~/workspace/pset5 $ ls
Makefile       dictionary.c  dictionary.o  pset5.zip      speller*   speller.o
dictionaries/  dictionary.h  keys/         questions.txt  speller.c  texts/
~/workspace/pset5 $ 
*/