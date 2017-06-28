# Compiler
CC := gcc

# Compiler options
FLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

main.exe: main.o snp.o
	$(CC) $^ -o main.exe
	
test.exe: test.o snp.o
	$(CC) $^ -o test.exe

snp.o: snp.c snp.h
	$(CC) $(FLAGS) -c snp.c
	
main.o: main.c snp.h
	$(CC) $(FLAGS) -c main.c
	
test.o: test.c snp.h
	$(CC) $(FLAGS) -c test.c
	
clean:
	$(RM) *.o *.exe