/* ----- MAIN ----- */
/// \author Binh Nguyen Duc
/// \details using functions in "strlib.h"

#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

int main()
{
	const char *s1 = "system is protected";
	const char *s2 = "restorecrtmode";
	
	char *c = _strpbrk(s1, s2);
	printf("[1. strpbrk] Result: ");
	if (c == NULL)
		printf("No char is found!\n");
	else
		if (*c == ' ')
			printf("(space)\n");
		else
			printf("%c\n", *c);
	
	char *s = _strdup(s1);
	printf("\n[2. strdup] Duplicated string: %s\n", s);
	free(s);
	
	return 0;
}