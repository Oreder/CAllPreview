/* ----- TEST ----- */
/// \author Binh Nguyen Duc
/// \details modulo tests functions in "strlib.h" and compares to same functions of "string.h"
/// 		 using standard "GNU99"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strlib.h"

int main()
{
	int err = 0;
	printf("# TEST \"strdup\":\n\n");

		/* STRDUP */
	const char *s_1 = "";			// NULL
	const char *s_2 = "  ";			// SPACE
	const char *s_3 = "b";			// SHORT
	const char *s_4 = "hjKDH7fa3$wtomb";	// MEDIUM
	const char *s_5 = "1234#C Programming Language __.$()!gnu99";	// LONG
	const char *s_6 = " .. gnu $STANDARD   ";	// space ending
	const char *s_7 = "09175717295";			// numbers
	
	char *a, *b;
	
	a = _strdup(s_1);
	b = strdup(s_1);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_2);
	b = strdup(s_2);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_3);
	b = strdup(s_3);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_4);
	b = strdup(s_4);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_5);
	b = strdup(s_5);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_6);
	b = strdup(s_6);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	a = _strdup(s_7);
	b = strdup(s_7);
	if (strcmp(a, b) != 0)
		err++;
	free(a); free(b);
	
	printf("Total error: %d", err);
	
	if (err)
		printf("     -- Result: FAIL!\n");
	else
		printf("     -- Result: PASS!\n");
	
	return 0;
}