#
# Makefile
# 2022 Feb 26, revised to added in cs50 dir
#
# Computer Science 50
# Problem Set 3
#

all: find generate

find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c ../cs50/cs50.c -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate

#Let’s finish looking at that Makefile. Notice the line below.

#all: find generate

# This target implies that you can build both generate and find simply by executing the below.
#make all
#Even better, the below is equivalent (because make builds a Makefile's first target by default).

#make

#If only you could whittle this whole problem set down to a single command! Finally, notice these last lines in Makefile:

#clean:
#    rm -f *.o a.out core find generate

#This target allows you to delete all files ending in .o or called core (more on that soon!), find, or generate simply by executing the command below.

#make clean
