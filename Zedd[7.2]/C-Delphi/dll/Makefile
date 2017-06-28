test.exe: test.o lib.o
	gcc $^ -o test.exe
	
lib.o: lib.c lib.h
	gcc -std=c99 -Wall -Werror -pedantic -D EXPORTS -c lib.c
	
test.o:	test.c lib.h
	gcc -std=c99 -Wall -Werror -pedantic -D EXPORTS -c test.c