# Compiler
CC := gcc

# Compiler options
FLAG := -std=c99 -Wall -Werror -ggdb

main.exe: main.o stack.o
	$(CC) $^ -o main.exe
	
test.exe: test.o stack.o
	$(CC) $^ -o test.exe
	
stack.o: stack.c stack.h
	$(CC) $(FLAG) -c stack.c
	
main.o: main.c stack.h
	$(CC) $(FLAG) -c main.c
	
test.o: test.c stack.h
	$(CC) $(FLAG) -c test.c
	
clean:
	$(RM) *.o *.exe