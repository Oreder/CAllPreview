/* ----- TEST ----- */
/// \author Binh Nguyen Duc
/// \details modulo tests functions in "strlib.h" and compares to same functions of "string.h"
/// 		 using standard "C99"

#include <stdio.h>
#include <string.h>
#include "strlib.h"

int main()
{
	int err = 0;
	printf("# TEST \"strpbrk\":\n\n");
	
		/* STRPBRK */
	const char *src = "1234#C Programming Language __.$()!gnu99";
	const char *s_1 = "";				// NULL
	const char *s_2 = "  ";				// SPACE
	const char *s_3 = "asbdf";			// letter
	const char *s_4 = "  C99";			// beginning 
	const char *s_5 = "rrrrrr";			// same char
	const char *s_6 = "55L";			// middle
	const char *s_7 = "b009";			// ending
	const char *s_8 = "007007%";		// none
	
	char *c, *d;

	c = _strpbrk(src, s_1);
	d = strpbrk(src, s_1);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_2);
	d = strpbrk(src, s_2);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_3);
	d = strpbrk(src, s_3);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_4);
	d = strpbrk(src, s_4);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_5);
	d = strpbrk(src, s_5);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_6);
	d = strpbrk(src, s_6);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_7);
	d = strpbrk(src, s_7);
	if (c != d)
		err++;
	
	c = _strpbrk(src, s_8);
	d = strpbrk(src, s_8);
	if (c != d)
		err++;
	
	c = _strpbrk(s_1, src);
	d = strpbrk(s_1, src);
	if (c != d)
		err++;
	
	c = _strpbrk(s_2, src);
	d = strpbrk(s_2, src);
	if (c != d)
		err++;
	
	c = _strpbrk(s_3, src);
	d = strpbrk(s_3, src);
	if (c != d)
		err++;
	
	c = _strpbrk(s_7, src);
	d = strpbrk(s_7, src);
	if (c != d)
		err++;
	
	printf("Total error: %d", err);
	
	if (err)
		printf("     -- Result: FAIL!\n");
	else
		printf("     -- Result: PASS!\n");
	
	return 0;
}