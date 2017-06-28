# Compiler
CC := gcc

# Compiler DrMemory options
DRM := -std=c99 -Wall -Werror -ggdb

main.exe: main.o read.o
	$(CC) main.o read.o -o main.exe
	
read.o: read.c limits.h read.h
	$(CC) $(DRM) -c read.c
	
main.o: main.c read.h
	$(CC) $(DRM)  -c main.c
	
clean: 
	$(RM) *.o *.exe