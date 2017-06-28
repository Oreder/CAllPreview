# Compiler
CC := gcc

# Compiler options
CFLAGS := -std=c99 -Wall -Werror -pedantic

a.exe: time.o sort.o
	$(CC) time.o sort.o -o a.exe
	
sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c
	
time.o: time.c sort.h
	$(CC) $(CFLAGS) -c time.c
	
clean:
	$(RM) *.o *.exe