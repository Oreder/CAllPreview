# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

main.exe: main.o read.o
	$(CC) main.o read.o -o main.exe
	
test.exe: test.o read.o
	$(CC) test.o read.o -o test.exe
	
read.o: read.c read.h limits.h
	$(CC) $(CFLAGS) -c read.c
	
main.o: main.c read.h
	$(CC) $(CFLAGS) -c main.c
	
test.o: test.c read.h
	$(CC) $(CFLAGS) -c test.c
	
clean:
	$(RM) *.o *.exe