# Compiler
CC := gcc

# Compiler options
FLAG := -std=c99 -Wall -Werror -ggdb

main.exe: main.o
	$(CC) $^ -o main.exe

stack.o: stack.c stack.h
	$(CC) $(FLAG) -c $^

main.o: main.c stack.h
	$(CC) $(FLAG) -c $^

clean:
	$(RM) *.o *.exe