# Compiler
CC := gcc

# Compiler DrMemory options
DRM := -std=c99 -Wall -Werror -ggdb

drmain.exe: main.o read.o
	$(CC) main.o read.o -o drmain.exe
	
drtest.exe: test.o read.o
	$(CC) test.o read.o -o drtest.exe	
	
read.o: read.c read.h limits.h
	$(CC) $(DRM) -c read.c
	
main.o: main.c read.h
	$(CC) $(DRM) -c main.c
	
test.o: test.c read.h
	$(CC) $(DRM) -c test.c
	
clean:
	$(RM) *.o *.exe