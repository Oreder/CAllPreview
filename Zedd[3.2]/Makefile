# Compiler
CC := gcc

# Compiler options
FLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

main.exe: main.o lib.o rep.o err.o
	$(CC) $^ -o main.exe
	
test.exe: test.o lib.o rep.o
	$(CC) $^ -o test.exe

lib.o: lib.c rep.h lib.h
	$(CC) $(FLAGS) -c lib.c
	
rep.o: rep.c rep.h
	$(CC) $(FLAGS) -c rep.c
	
err.o: err.c err.h
	$(CC) $(FLAGS) -c err.c
	
main.o: main.c lib.h rep.h err.h
	$(CC) $(FLAGS) -c main.c
	
test.o: test.c lib.h rep.h
	$(CC) $(FLAGS) -c test.c

clean:
	$(RM) *.o *.exe