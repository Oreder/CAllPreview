# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

pro.exe:  size.o read.o search.o main.o
	$(CC) size.o read.o search.o main.o -o pro.exe
	
test.exe: size.o read.o search.o test.o
	$(CC) size.o read.o search.o test.o -o test.exe	
	
size.o: size.c size.h
	$(CC) $(CFLAGS) -c size.c
	
read.o: read.c read.h
	$(CC) $(CFLAGS) -c read.c

search.o: search.c search.h
	$(CC) $(CFLAGS) -c search.c
	
main.o: main.c size.h read.h search.h
	$(CC) $(CFLAGS) -c main.c

test.o: test.c size.h read.h search.h
	$(CC) $(CFLAGS) -c test.c	
	
clean:
	$(RM) *.o *.exe