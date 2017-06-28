/* ----- FILTER() TEST ----- */
/// \author Binh Nguyen Duc
/// \brief  Module tests function filter() in library "filter.c"

#include <stdio.h>
#include "filter.h"


/// \author Binh Nguyen Duc
/// \brief  function checks 2 arrays
/// param[in] pointers to begining of 2 arrays and number its' member

int check(const int *p, const int *q, size_t nmemb)
{
	int i;
	for (i = 0; i < nmemb; i++)
		if (*(p + i) != *(q + i))
			return -1;
	return 0;
}


int main()
{
	int E = 0;		// ERROR
	
	/* ----- SIZE_OUT test ----- */
	const int a[5] = {1, 2, 3, 4, 5};
	if (size_out(a, a+5) != 0)
		E++;
	
	const int b[5] = {-1, -2, -3, -4, -5};
	if (size_out(b, b+5) != 4)
		E++;
	
	const int c[2] = {10, 9};
	if (size_out(c, c+2) != 1)
		E++;
	
	/* ----- GET_FILTER test ----- */
	// b[5] = {-1, -2, -3, -4, -5};
	const int B[4] = {-4, -3, -2, -1};
	int pb[4];
	get_filter(b, b+5, pb);
	if (check(pb, B, 4))
		E++;
	
	// c[2] = {10, 9};
	const int C[1] = {10};
	int pc[1];
	get_filter(c, c+2, pc);
	if (check(pc, C, 1))
		E++;
	
	printf("\nError found: %d\n", E);		// print number of error
	if (!E)
		printf("\n --- Test result: PASS!\n");
	else
		printf("\n --- Test result: FAIL!\n");
	return 0;
}