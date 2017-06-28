/* ----- MAIN ----- */
/// \author Binh Nguyen Duc
/// \brief 	Example of funtions PART_SNPRINTF with signals %s, %o and %c

#include <stdio.h>
#include <string.h>
#include "snp.h"

int main()
{
	char str[50];
	int re = part_snprintf(str, 10, "%ceeloo %s%o", 'H', "asaw", -12);
	printf("Va: %d\n\n", re);
	puts(str);
	
	char as[50];
	int aw = snprintf(as, 10, "%ceeloo %s%o", 'H', "asaw", -12);
	printf("\n\nVa: %d\n\n", aw);
	puts(as);
	
	printf("RES: %d\n", strcmp(as, str));
	
	return 0;
}
