# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

main.exe: main.o read.o filter.o bsort.o
	$(CC) main.o read.o filter.o bsort.o -o main.exe

test.exe: btest.o bsort.o
	$(CC) btest.o bsort.o -o test.exe
	
ftr.exe: ftest.o filter.o
	$(CC) ftest.o filter.o -o ftr.exe

a.exe: time.o bsort.o
	$(CC) time.o bsort.o -o a.exe
	
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
	
ftest.o: ftest.c filter.h
	$(CC) $(CFLAGS) -c ftest.c
	
time.o: time.c bsort.h
	$(CC) $(CFLAGS) -c time.c
	
clean :
	$(RM) *.o *.exe