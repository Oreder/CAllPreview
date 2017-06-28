# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

# Objects file
OBJS := div.o read.o lib.o

main.exe: main.o $(OBJS)
	$(CC) main.o $(OBJS) -o main.exe
	
test.exe: test.o divmem.o lib.o
	$(CC) test.o divmem.o lib.o -o test.exe
	
div.o: divmem.c divmem.h
	$(CC) $(CFLAGS) -c divmem.c -o div.o
	
read.o: read.c read.h divmem.h
	$(CC) $(CFLAGS) -c read.c
	
lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c
	
main.o: main.c divmem.h read.h lib.h
	$(CC) $(CFLAGS) -c main.c

test.o: test.c divmem.h lib.h
	$(CC) $(CFLAGS) -c test.c
	
clean:
	$(RM) *.o *.exe