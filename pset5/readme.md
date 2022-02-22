


``` console
antw@Mac-mini pset5 % ls  
Makefile	dictionary.h	pset5.zip	speller.c
dictionaries	dictionary.o	questions.txt	speller.o
dictionary.c	keys		speller		texts
antw@Mac-mini pset5 % rm speller
remove speller? y
antw@Mac-mini pset5 % make
clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -o speller speller.o dictionary.o 
antw@Mac-mini pset5 % ./speller texts/austen.txt
...
...

WORDS MISSPELLED:     1614
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        125203
TIME IN load:         0.03
TIME IN check:        0.10
TIME IN size:         0.00
TIME IN unload:       0.02
TIME IN TOTAL:        0.16

antw@Mac-mini pset5 % 
```
``` console
antw@Mac-mini pset5 % ./speller texts/holmes.txt
...
...
WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970
TIME IN load:         0.03
TIME IN check:        0.96
TIME IN size:         0.00
TIME IN unload:       0.02
TIME IN TOTAL:        1.02

antw@Mac-mini pset5 % 
```
