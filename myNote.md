
Creating a "Hello, world" C program

hello.c
``` c
#include < stdio.h >

int main() {

   printf(" Hello world!\n");
   return 1; 
}
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
