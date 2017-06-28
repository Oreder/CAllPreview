REM :: LINK DYNAMICALLY

gcc -std=c99 -Wall -Werror -pedantic -c main.c

gcc main.o -L. -larr -o test.exe

pause