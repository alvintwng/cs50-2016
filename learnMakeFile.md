MakeFile Tutorial
---
* Intro
* Basic Makefile
* Build Rules
* How Make Works
* Separate Compilation
* Automatic Variables

### Intro
```c
$ ls
hello.cpp hello.h main.cpp makefile
$ g++ main.cpp hello.cpp -o main.out
$ ./main.out
hello world
$ rm main.out
$ cat *
// hello.cpp
#include <iostream>
#include "hello.h"

void hello()
{
    std::cout << "Hello World" << std::endl;
}

// hello.h
void hello();

// main.cpp
#include "hello.h"

int main()
{
    hello();
}
```
targets...: target-pattern: prereq-patterns ...

### Basic Makefile

makefile, using Notes to create this file. Tab once.
```c
main.out: hello.cpp main.cpp
	g++ main.cpp hello.cpp -o main,out
```

```console
antw@Mac-mini c % ls
hello.cpp	hello.h		main.cpp	makefile
antw@Mac-mini c % make
g++ main.cpp hello.cpp -o main.out
antw@Mac-mini c % ls
hello.cpp	hello.h		main.cpp	main.out	makefile
antw@Mac-mini c % ./main.out
Hello World
antw@Mac-mini c % 
```

### Build Rules
It will compile when are changes on files shown older with output.
```console
antw@Mac-mini c % make
make: `main.out' is up to date.
antw@Mac-mini c % ls -lh
total 80
-rw-r--r--  1 antw  staff   115B Mar 25 14:15 hello.cpp
-rw-r--r--  1 antw  staff    26B Mar 25 14:12 hello.h
-rw-r--r--  1 antw  staff    61B Mar 25 14:13 main.cpp
-rwxr-xr-x  1 antw  staff    55K Mar 25 14:28 main.out
-rw-r--r--@ 1 antw  staff    65B Mar 25 14:27 makefile
antw@Mac-mini c % touch main.cpp
antw@Mac-mini c % ls -lh
total 80
-rw-r--r--  1 antw  staff   115B Mar 25 14:15 hello.cpp
-rw-r--r--  1 antw  staff    26B Mar 25 14:12 hello.h
-rw-r--r--  1 antw  staff    61B Mar 25 14:32 main.cpp
-rwxr-xr-x  1 antw  staff    55K Mar 25 14:28 main.out
-rw-r--r--@ 1 antw  staff    65B Mar 25 14:27 makefile
antw@Mac-mini c % make
g++ main.cpp hello.cpp -o main.out
antw@Mac-mini c % 
```

### How Make Works
`Make` wil compile the files that need to recompile.
So if there are files that do not need to recompile, will not recompile, that actually saved alot of time.


### Separate Compilation
makefile
```c
main.out: hello.o main.o
	g++ main.o hello.o -o main.out

hello.o: hello.cpp
	g++ -c hello.cpp -o hello.o

main.o: main.cpp
	g++ -c main.cpp -o main.o
```
```console
antw@Mac-mini c % make
g++ -c hello.cpp -o hello.o
g++ -c main.cpp -o main.o
g++ main.o hello.o -o main.out
antw@Mac-mini c % ./main.out
Hello World
antw@Mac-mini c % vim main.cpp
```

main.cpp
```c
// main.cpp
#include "hello.h"

int main()
{
    hello();
    hello();
}
```
```console
antw@Mac-mini c % make
g++ -c main.cpp -o main.o
g++ main.o hello.o -o main.out
antw@Mac-mini c % 
```
Shown that it only compiled `main.cpp`

### Automatic Variables
makefile, `S{CC}`, use on `clang`, or `gcc`
```c
CC = g++

main.out: hello.o main.o
	${CC} main.o hello.o -o main.out

hello.o: hello.cpp
	${CC} -c hello.cpp -o hello.o

main.o: main.cpp
	${CC} -c main.cpp -o main.o
```
``` console
antw@Mac-mini c % make
make: `main.out' is up to date.
antw@Mac-mini c % touch main.cpp
antw@Mac-mini c % make          
g++ -c main.cpp -o main.o
g++ main.o hello.o -o main.out
```
makefile, `${FLAGS}`
```c
CC = g++
FLAGS = -O3

main.out: hello.o main.o
	${CC} ${FLAGS} main.o hello.o -o main.out

hello.o: hello.cpp
	${CC} ${FLAGS} -c hello.cpp -o hello.o

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp -o main.o
```
``` console
antw@Mac-mini c % touch main.cpp
antw@Mac-mini c % make          
g++ -O3 -c main.cpp -o main.o
g++ -O3 main.o hello.o -o main.out
```

makefile, `$@` target file
```c
CC = g++
FLAGS = -O3

main.out: hello.o main.o
	${CC} ${FLAGS} main.o hello.o -o $@

hello.o: hello.cpp
	${CC} ${FLAGS} -c hello.cpp -o $@

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp -o $@
```
``` console
antw@Mac-mini c % vim makefile
antw@Mac-mini c % make
make: `main.out' is up to date.
antw@Mac-mini c % touch main.cpp
antw@Mac-mini c % make          
g++ -O3 -c main.cpp -o main.o
g++ -O3 main.o hello.o -o main.out
antw@Mac-mini c % 
```

makefile, `$^` prerequisites file
```c
CC = g++
FLAGS = -O3

main.out: hello.o main.o
	${CC} ${FLAGS} $^ -o $@

hello.o: hello.cpp
	${CC} ${FLAGS} -c $^ -o $@

main.o: main.cpp
	${CC} ${FLAGS} -c $^ -o $@
```
``` console
antw@Mac-mini c % make
g++ -O3 -c hello.cpp -o hello.o
g++ -O3 -c main.cpp -o main.o
g++ -O3 hello.o main.o -o main.out
```

---

Ref:  https://www.youtube.com/watch?v=U1I5UY_vWXI

Also check on [makefiletutorial.com](https://makefiletutorial.com/)


