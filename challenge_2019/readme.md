readme.md

For the folder *dictionaries*, *keys* amd *texts* may refere to [cs50-2016/pset5/](https://github.com/alvintwng/cs50-2016/tree/master/pset5) 

cs50-2016/pset5/questions.txt:

0.  Pneumonoultramicroscopicsilicovolcanoconiosis is an artificial long word said to mean a lung disease caused by inhaling very fine ash, sand dust or silica dust, it also know as silicosis.
1.  Getrusage is to get information about resource utilisation. It will return resource statistics data with 0 for success, -1 for fail. For this case, getrusage is to measure the resource usage and execution time.
2.  From the 'man getrusage', there are 16 members of this struct.
3.  The ‘before' and ‘ after' are pointers of struct rusage. Both of these variables collect timing data, that determine the start and stop of process. The calculate will bases on these two referenced addresses' value to process data.
4.  The for-loop is function of initialised, compare and process. This For-Loop is to feed character by character to form a word, and end with "\0".
At the initial, 'int c = fgetc(fp)', it set c as interger, than to get bytes from external data files. The 'c != EOF’ which compare End-Of-File(EOF) error, if not EOF, just continue, otherwise out of loop. The 'c = fgetc(fp)' will commands the update, which for this case to call c to get another character from the file(fp).
5.  With fgetc, it is flexible to decide type of word to accept, such as to ignore word that is longer than predetermine size, ignore word that consist of numeric digit, avoid any char after the apostrophes. It also accept words with any special code, such as !{]|$%& beside the word, these code will be treated as space, that is accept word divided by this special code. If fscanf is to be used, the word need to copy into char array to process. 
6.  Const char* is a pointer to a constant character, hence, you can't change the value point at. The value from function with const variable will not be able to alter, it will be advantage for more users using this function.
7.  Using link list-nodes, and hash-tables. Link list with members of char* word that will hold word to be process, and 'struct node* next' which hold reference to the next link-list node. For the hash-table is array struct with only member of 'struct node* next', that hold the reference to link-list node. Using ‘strcmp’ for spell-check, the word at the link-list will be compare against the dictionary’s words.
8.  Loaded dictionary at 0.66sec, and spell-checked holme.txt at 9.0 sec.
9.  After changed the sequence of link nodes; increased the hash value; removed functions that were redundant; reduced memory leak; and changed hash formula. Now the 'loaded dictionary time' is at  0.04sec, and 'spell-checked' holme.txt at 0.94 sec, which is 10 times faster!
10. On the software, the bottlenecks will be unable to use ‘binary search’ the sequence of link-list nodes for spell-checking. The hardware depend on the speed of computer, as well as the interface between CS50 IDE environment and local computer, especially when transferring data via the fgetc, or fscanf words from external data files.


terminal
``` console
antw@Mac-mini challenge_2019 % make
make: `speller' is up to date.
antw@Mac-mini challenge_2019 % ls -la spe*
-rwx------@ 1 antw  staff  22136 Sep 29  2019 speller
-rw-r--r--@ 1 antw  staff   5076 Oct  6  2018 speller.c
-rw-------@ 1 antw  staff  14744 Sep 29  2019 speller.o
```
