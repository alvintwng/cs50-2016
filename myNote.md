
Creating a "Hello, world" C program

hello.c
``` c
#include < stdio.h >

int main() {

   printf(" Hello world!\n");
   return 1; 
}
```
``` c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./hello <text>\n");
        return 1;
    }

    char* name = argv[1];

    printf("hello, %s\n", name);
}

// sh-3.2$ vim hello.c
// sh-3.2$ gcc -g -Wall hello.c -o hello
// sh-3.2$ ./hello World!
// hello, World!
```

### gcc hello.c
terminal
``` console
antw@Mac-mini scripts % gcc -v  
  ...
  Apple clang version 12.0.5 (clang-1205.0.22.11)
  ...
antw@Mac-mini scripts % gcc -g hello.c
antw@Mac-mini scripts % ./a.out
  hello, world
  
antw@Mac-mini scripts % gcc -g hello.c  -o hello
antw@Mac-mini scripts % ./hello
hello, world

antw@Mac-mini scripts % gcc -g -Wall hello.c -o hello
antw@Mac-mini scripts % ./hello                      
hello, world
```

ref: https://tildesites.bowdoin.edu/~ltoma/teaching/cs3225-GIS/fall16/Lectures/basics.html

---
Makefile
``` Makefile
#   Makefile
#   2022 Feb 22
#
#
#

hello: hello.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o hello hello.c -lm

clean:
	rm -f *.o a.out core

```


---
Working software on Mac-mini:

[mymergesort.c](/pset3/hackerfind/mymergesort.c)

also

[mergesort.c](/pset3/hackerfind/mergesort.c)
``` console
antw@Mac-mini c % vi mergesort.c
antw@Mac-mini c % gcc -g -Wall mergesort.c -o mergesort
antw@Mac-mini c % ./mergesort
{ 80, 15, 16, 50, 10, 23, 42, 99, }
{ 10, 15, 15, 16, 23, 42, 50, 99, }
```
