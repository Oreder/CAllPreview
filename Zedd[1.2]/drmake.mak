# Compiler
CC := gcc

# Compiler DrMemory options
DRM := -std=c99 -Wall -Werror -ggdb

main.exe: main.o read.o filter.o bsort.o
	$(CC) main.o read.o filter.o bsort.o -o main.exe

test.exe: btest.o bsort.o
	$(CC) btest.o bsort.o -o test.exe
	
read.o: read.c read.h
	$(CC) $(CFLAGS) -c read.c
	
filter.o: filter.c filter.h
	$(CC) $(CFLAGS) -c filter.c
	
bsort.o: bsort.c bsort.h
	$(CC) $(CFLAGS) -c bsort.c
	
main.o: main.c read.h filter.h bsort.h
	$(CC) $(CFLAGS) -c main.c
	
btest.o: btest.c bsort.h
	$(CC) $(CFLAGS) -c btest.c
	
clean :
	$(RM) *.o *.exe