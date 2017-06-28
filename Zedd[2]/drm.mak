# Compiler
CC := gcc

# Compiler options
DRM := -std=c99 -Wall -Werror -ggdb

# Objects file
OBJS := div.o read.o lib.o

main.exe: main.o $(OBJS)
	$(CC) main.o $(OBJS) -o main.exe
	
test.exe: test.o div.o lib.o
	$(CC) test.o div.o lib.o -o test.exe
	
div.o: divmem.c divmem.h
	$(CC) $(DRM) -c divmem.c -o div.o
	
read.o: read.c read.h divmem.h
	$(CC) $(DRM) -c read.c
	
lib.o: lib.c lib.h
	$(CC) $(DRM) -c lib.c
	
main.o: main.c divmem.h read.h lib.h
	$(CC) $(DRM) -c main.c
	
test.o: test.c divmem.h lib.h
	$(CC) $(DRM) -c test.c
	
clean:
	$(RM) *.o *.exe