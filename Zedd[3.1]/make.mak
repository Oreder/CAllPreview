# Compiler
CC := gcc

# Compiler options
DRM := -std=c99 -Wall -Werror -ggdb

# Compiler GNU
GNU := -std=gnu99 -Wall -Werror -ggdb

main.exe: main.o strlib.o
	$(CC) main.o strlib.o -o main.exe
	
a.exe: test.o strlib.o
	$(CC) test.o strlib.o
	
b.exe: duptest.o strlib.o
	$(CC) duptest.o strlib.o -o b.exe
	
strlib.o: strlib.c strlib.h
	$(CC) $(DRM) -c strlib.c
	
main.o: main.c strlib.h
	$(CC) $(DRM) -c main.c
	
test.o: test.c strlib.h
	$(CC) $(DRM) -c test.c
	
duptest.o: duptest.c strlib.h
	$(CC) $(GNU) -c duptest.c
	
clean:
	$(RM) *.o *.exe