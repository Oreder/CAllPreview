gcc -std=c99 -Wall -Werror -pedantic -c lib.c
ar rc lib.a lib.o
ranlib lib.a