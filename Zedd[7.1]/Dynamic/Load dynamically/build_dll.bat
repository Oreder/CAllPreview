gcc -std=c99 -Wall -Werror -pedantic -D ARR_EXPORTS -c lib.c

gcc -shared lib.o -Wl,--subsystem,windows -o arr.dll