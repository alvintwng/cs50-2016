wk5-A

scanf-0.c
```console
antw@Mac-mini wk5-A % gcc -g -Wall scanf-0.c -o scanf-0.ex
antw@Mac-mini wk5-A % ./scanf-0.ex
Number please: 123
Thanks for the 123!
antw@Mac-mini wk5-A %   
```
scanf-1.c
``` console
antw@Mac-mini wk5-A % gcc -g -Wall scanf-1.c -o scanf-1.ex
scanf-1.c:18:17: warning: variable 'buffer' is uninitialized when used here [-Wuninitialized]
    scanf("%s", buffer);
                ^~~~~~
scanf-1.c:16:17: note: initialize the variable 'buffer' to silence this warning
```

scanf-2.c
``` console
antw@Mac-mini wk5-A % gcc -g -Wall scanf-2.c -o scanf-2.ex
antw@Mac-mini wk5-A % ./scanf-2.ex
String please: hello world
Thanks for the hello!
antw@Mac-mini wk5-A % 
```
memory.c
``` console
antw@Mac-mini wk5-A % gcc -g -Wall memory.c -o memory.ex 
antw@Mac-mini wk5-A % ./memory.ex
antw@Mac-mini wk5-A % 
```
list-0.c
``` console
antw@Mac-mini wk5-A % gcc -g -Wall list-0.c -o list-0.ex
list-0.c:10:10: error: 'cs50.h' file not found with <angled> include; use "quotes" instead
#include <cs50.h>
         ^~~~~~~~
         "cs50.h"
1 error generated.
antw@Mac-mini wk5-A % vim list-0.c                      
antw@Mac-mini wk5-A % gcc -g -Wall list-0.c -o list-0.ex
Undefined symbols for architecture x86_64:
  "_GetInt", referenced from:
      _main in list-0-5c26c3.o
      _delete in list-0-5c26c3.o
      _insert in list-0-5c26c3.o
      _search in list-0-5c26c3.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
antw@Mac-mini wk5-A % 
```
list-1.c
``` console
antw@Mac-mini wk5-A % gcc -g -Wall list-1.c -o list-1.ex
list-1.c:10:10: error: 'cs50.h' file not found with <angled> include; use "quotes" instead
#include <cs50.h>
         ^~~~~~~~
         "cs50.h"
1 error generated.
antw@Mac-mini wk5-A % vim list-1.c
antw@Mac-mini wk5-A % gcc -g -Wall list-1.c -o list-1.ex
Undefined symbols for architecture x86_64:
  "_GetInt", referenced from:
      _main in list-1-e35aa6.o
      _delete in list-1-e35aa6.o
      _insert in list-1-e35aa6.o
      _search in list-1-e35aa6.o
  "_GetString", referenced from:
      _insert in list-1-e35aa6.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
antw@Mac-mini wk5-A % 
```
