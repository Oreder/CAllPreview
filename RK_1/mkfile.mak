# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

main.exe: main.o read.o
	$(CC) main.o read.o -o main.exe
	
read.o: read.c read.h limits.h
	$(CC) $(CFLAGS) -c read.c
	
main.o: main.c read.h
	$(CC) $(CFLAGS) -c main.c
	
clean: 
	$(RM) *.o *.exe