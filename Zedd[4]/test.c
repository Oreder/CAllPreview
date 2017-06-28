/* ----- TEST ----- */
/// \author  Binh Nguyen Duc
/// \details Test "snprinf" in standard library with "part_snprintf"
/// 		 in library "snp.h"; Signals are tested including %s %o %c

#include <stdio.h>		/* SNPRINTF */
#include <stdlib.h>		/* FREE, MALLOC */
#include <assert.h>
#include <string.h>		/* STRCMP   */
#include <limits.h>
#include "snp.h"		/* PART_SNPRINTF */

int main()
{
	printf("TEST:\n\n");
	
		/* ----- TEST: CONVERT ----- */
	printf("+ Function \"convert\": ");
	int err = 0;
	char *oct;
	assert((oct = convert(0)));
	if (strcmp(oct, "0") != 0)
		err++;
	free(oct);
	
	assert((oct = convert(8)));
	if (strcmp(oct, "10") != 0)
		err++;
	free(oct);
	
	assert((oct = convert(472)));
	if (strcmp(oct, "730") != 0)
		err++;
	free(oct);
	
	assert((oct = convert(35209)));
	if (strcmp(oct, "104611") != 0)
		err++;
	free(oct);
	
	assert((oct = convert(2147483647)));
	if (strcmp(oct, "17777777777") != 0)
		err++;
	free(oct);
	
	if (!err)
		printf("PASS!\n\n");
	else
		printf("FAIL!\n\n");
	
	
		/* ----- Test "PART_SNPRINTF" vs. "SNPRINTF" ----- */
	printf("+ Test \"PART_SNPRINTF\" vs. \"SNPRINTF\": ");
	err = 0;
	int pv, sv;
	char str[50], str_1[50];
	const char src[] = "Hello, world!\n";		/* TEST SIGNAL %s */
	
	sv = snprintf(str, 20, "%s", src);				// CASE: LONG size_t
	pv = part_snprintf(str_1, 20, "%s", src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;
	
	sv = snprintf(str, 15, "%s", src);				// CASE: FULL size_t
	pv = part_snprintf(str_1, 15, "%s", src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;
	
	sv = snprintf(str, 9, "%s", src);				// CASE: SHORT size_t
	pv = part_snprintf(str_1, 9, "%s", src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;
	
	sv = snprintf(str, 1, "%s", src);				// CASE: NULL
	pv = part_snprintf(str_1, 1, "%s", src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;

												/* TEST SIGNAL %o */
	sv = snprintf(str, 5, "%o", 0);										
	pv = part_snprintf(str_1, 5, "%o", 0);			// CASE: SHORT decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with LONG size_t
		err++;
	
	sv = snprintf(str, 1, "%o", 12);										
	pv = part_snprintf(str_1, 1, "%o", 12);			// CASE: SHORT decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with SHORT size_t
		err++;
	
	sv = snprintf(str, 13, "%o", 12345);										
	pv = part_snprintf(str_1, 13, "%o", 12345);		// CASE: LONG decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with LONG size_t
		err++;
	
	sv = snprintf(str, 6, "%o", 12345);										
	pv = part_snprintf(str_1, 6, "%o", 12345);		// CASE: LONG decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with SHORT size_t
		err++;

	sv = snprintf(str, 13, "%o", 2147483647);										
	pv = part_snprintf(str_1, 13, "%o", 2147483647);	// CASE: LONG decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with LONG size_t
		err++;
	
	sv = snprintf(str, 6, "%o", 2147483647);										
	pv = part_snprintf(str_1, 6, "%o", 2147483647);	// CASE: LONG decimal
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// 		 with SHORT size_t
		err++;
	
	const char c = '*';							/* TEST SIGNAL %c */
	
	sv = snprintf(str, 2, "%c", c);										
	pv = part_snprintf(str_1, 2, "%c", c);			// CASE: SHORT size_t
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;
	
	sv = snprintf(str, 12, "%c", c);										
	pv = part_snprintf(str_1, 12, "%c", c);			// CASE: LONG size_t
	if ((pv != sv) || (strcmp(str, str_1) != 0))
		err++;

												/* COMBINATION TEST */
	sv = snprintf(str, 50, "%s %c%o", src, 'i', 0);
	pv = part_snprintf(str_1, 50, "%s %c%o", src, 'i', 0);
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: 3 signals (mixed)
		err++;									// 		 with LONG size_t 
	
	sv = snprintf(str, 10, "%c %o%s", 'i', 1001, src);
	pv = part_snprintf(str_1, 10, "%c %o%s", 'i', 1001, src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: 3 signals (mixed)
		err++;									// 		 with SHORT size_t
	
	sv = snprintf(str, 30, "%c%c%o%s", 'i', c, 2015, src);
	pv = part_snprintf(str_1, 30, "%c%c%o%s", 'i', c, 2015, src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: 4 signals (mixed)
		err++;
	
												/* COMBINATION WITH CONST STRING-OUT */
	sv = snprintf(str, 50, "Character '%c' is not in %s", 'G', src);
	pv = part_snprintf(str_1, 50, "Character '%c' is not in %s", 'G', src);
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: Normal string-out	(*)
		err++;

	sv = snprintf(str, 31, "Result: 128 (Dec) -> %o (Oct)", 128);
	pv = part_snprintf(str_1, 31, "Result: 128 (Dec) -> %o (Oct)", 128);
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: Normal string-out	(*)
		err++;

	sv = snprintf(str, 16, "Hello, I'm done!");
	pv = part_snprintf(str_1, 16, "Hello, I'm done!");
	if ((pv != sv) || (strcmp(str, str_1) != 0))				// CASE: NO SIGNALs in string-out	(*)
		err++;

char s[50] = {0}, s_1[50] = {0};
	sv = snprintf(s, 0, "%o %o", -1, UINT_MAX);
	pv = part_snprintf(s_1, 0, "%o %o", -1, UINT_MAX);
	if ((pv != sv) || (strcmp(s, s_1) != 0))				// CASE: 4 signals (mixed)
		err++;
	 printf("\n SV: %d  PV : %d", sv, pv);
	puts(s); printf("here");
	puts(s_1);
	
	if (!err)
		printf("PASS!\n");
	else
		printf("FAIL!\n");
	
	return 0;
}
