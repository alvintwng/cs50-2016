
``` console
antw@Mac-mini weeks % ls -l
total 24
-rw-r--r--  1 antw  staff   144 Mar 23 13:31 Makefile
-rw-r--r--  1 antw  staff  1955 Mar 23 13:31 collatz.c
-rw-r--r--  1 antw  staff  1083 Mar 23 13:31 factorial.c
antw@Mac-mini weeks % 
antw@Mac-mini weeks % make collatz                                                                  
cc     collatz.c   -o collatz
antw@Mac-mini weeks % ./collatz 6
 -> 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Collatz steps: 8

antw@Mac-mini weeks % make factorial
cc     factorial.c   -o factorial
antw@Mac-mini weeks % ./factorial 3
  n = 3
  n! = n * (n-1)!
  3! = 3 * 2!
  2! = 2 * 1!
  1! = 1 * 0!
  Factorial of 3 = 6
antw@Mac-mini weeks % ls
Makefile	collatz		collatz.c	factorial	factorial.c
antw@Mac-mini weeks % rm collatz factorial
remove collatz? y
remove factorial? y
```
