# Compiler
CC := gcc

# Compiler options
FLAG := -std=c99 -Wall -Werror -pedantic -ggdb

main.exe: main.o clist.o
	$(CC) $^ -o main.exe

clist.o: clist.c clist.h
	$(CC) $(FLAG) -c clist.c

main.o: main.c clist.h
	$(CC) $(FLAG) -c main.c

clean:
	$(RM) *.o *.exe
