/******
CS50-2019 pset 4 tries
video by Zamyla

TRIES
=====

# Tries
* every node contains an array of node pointers
* * one for every letter in the alphabet + " \' "
* * each element in the array points to another node
* * * if that node is NULL, then that letter isn't the next letter of any word in that sequence
* every node indicates whether it's the last character of a word

typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;
node *root;


# load
* for every dictionary word, iterate through the trie
* each element in children corresponds to a different letter
* check the value at childen[i]
* * if NULL, malloc a new node, have children[i] point to it
* * if not NULL, move to new node and continue
* if at end of word, set is_word to true

# check
* case-insensitivity
* assume strings with only alphabeticall characters and/or apostrophes

# traversing a trie
* for each letter in inout word
* * go to corresponding element in children
* * * if NULL, word is misspelled
* * * if not NULL, move to next letter
* * once at end of input word
* * * check if is_word is true

# freeing linked lists
node *cursor = head;
while (cursor != NULL)
{
    node *temp = cursor;
    cursor = cursor -> next;
    free(temp);
}

# unload
* unload from bottom to top
* travel to lowest possiblt node
* * free all pointers in children
* * backtrack upwards, freeing all elements in
* * each children array until you hit root node
* recursion!

# valgrind
valgrind --v --leak-check=full austinpowers.txt

# tips
* pass in a smaller dictionary
* * usuage: ./speller [dictionary] text
* * default: large
* * also try: small
* * make your own!
* pen and paper!


staff's solution | against 2019 Trie | against 2016 hash
~cs50/2019/x/pset4/speller dictionaries/large texts/shakespeare.txt
WORDS MISSPELLED:     45691
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        904612
TIME IN load:         0.02 | 0.06 | 0.03
TIME IN check:        0.64 | 0.57 | 0.74
TIME IN size:         0.00 | 0.03 | 0.00
TIME IN unload:       0.01 | 0.04 | 0.00
TIME IN TOTAL:        0.66 | 0.71 | 0.77

staff's solution | against 2019 Trie | against 2016 hash
~cs50/2019/x/pset4/speller dictionaries/large texts/grimm.txt
WORDS MISSPELLED:     718
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        103614
TIME IN load:         0.02 | 0.06 | 0.03
TIME IN check:        0.06 | 0.06 | 0.08
TIME IN size:         0.00 | 0.03 | 0.00
TIME IN unload:       0.01 | 0.04 | 0.01
TIME IN TOTAL:        0.08 | 0.19 | 0.11

staff's solution | against 2019 Trie | against 2016 hash | add size counter
~cs50/2019/x/pset4/speller dictionaries/large texts/holmes.txt
WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970
TIME IN load:         0.02 | 0.06 | 0.03 | 0.06
TIME IN check:        0.77 | 0.69 | 0.95 | 0.68
TIME IN size:         0.00 | 0.03 | 0.00 | 0.00
TIME IN unload:       0.01 | 0.04 | 0.00 | 0.04
TIME IN TOTAL:        0.80 | 0.83 | 0.98 | 0.79


valgrind --leak-check=full --show-leak-kinds=all ./speller texts/holmes.txt
valgrind at dictionary hash
==9002== HEAP SUMMARY:
==9002==     in use at exit: 0 bytes in 0 blocks
==9002==   total heap usage: 1,437,159 allocs, 1,437,159 frees, 15,104,259 bytes allocated
==9002==
==9002== All heap blocks were freed -- no leaks are possible
==9002==
==9002== For counts of detected and suppressed errors, rerun with: -v
==9002== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


valgrind at dictionary trie
==8902== HEAP SUMMARY:
==8902==     in use at exit: 0 bytes in 0 blocks
==8902==   total heap usage: 367,088 allocs, 367,088 frees, 82,236,912 bytes allocated
==8902==
==8902== All heap blocks were freed -- no leaks are possible
==8902==
==8902== For counts of detected and suppressed errors, rerun with: -v
==8902== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



****/
    sizeofnode : 224
    total size in dcitionary node of 143091 words : 32052384
    total size in dcitionary node of 3 words : 672
    total size 224 * 143091 words : 32052384 => wrong, not word but letters


for dictionary/cat
 * Count malloc: 4 => for 3 letters
total size of 4 malloc node : 896
==5000==     in use at exit: 928 bytes in 5 blocks
==5000==   total heap usage: 8 allocs, 3 frees, 5,800 bytes allocated
=> 224*4 + 4904 = 5800

for dictionary/large
* Count malloc: 367082
total size of 367082 malloc node : 82226368
==4845==     in use at exit: 82,226,400 bytes in 367,083 blocks
==4845==   total heap usage: 367,086 allocs, 3 frees, 82,231,272 bytes allocated
=> 224*367082 + 4904 = 82231272

for dictionary/small // for 'cat' & 'catch'
* Count malloc: 6 =>  for 5 letters
total size of 6 malloc node : 1344
==843==     in use at exit: 1,376 bytes in 7 blocks
==843==   total heap usage: 10 allocs, 3 frees, 6,248 bytes allocated
=> 224*6 + 4904 = 6248

for dictionary/small // for cat, catch, caterpillar
* Count malloc: 14 => for 13 letters
total size of 14 malloc node : 3136
==1868==     in use at exit: 3,168 bytes in 15 blocks
==1868==   total heap usage: 18 allocs, 3 frees, 8,040 bytes allocated
=> 224*14 + 4904 = 8040

added size counter
https://speller.cs50.io/challenge/34b2207e9745920e302fc96b6141ab03c3360fb1

tested at test.c
sizeof node for N=27 = 224 bytes, malloc 256 bytes
sizeof node for N=0 =  8 bytes, malloc 40 bytes
sizeof node for N=1 = 16 bytes, malloc 48 bytes
sizeof node for N=2 = 24 bytes, malloc 56 bytes
sizeof node for N=3 = 32 bytes, malloc 64 bytes, other 32 bytes
difference 8 bytes per children
 8 * (27 + 1 root) + 32 = 256
without  bool is_word, 248 bytes allocated
so bool is_word is 8 bytes

32 bytes if no malloc

33 bytes if only boo isword, sizeof isword is 1 byte
32 bytes if only boo is_word, and no malloc

x is 1 ; size of x= 4 ; size of &x= 8


look into use node with 1 child
typedef struct _trie
{
    char university[20];
    struct _trie *path[10];
}
trie;

/*** last done at
test.c
l.c
u.c



