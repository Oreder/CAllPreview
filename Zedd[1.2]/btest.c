/* ----- BSORT() TEST ----- */
/// \author Binh Nguyen Duc
/// \brief  Module tests function bsort() in library "bsort.c"

#include <stdio.h>
#include "bsort.h"

/// \author Binh Nguyen Duc
/// \brief  function checks error of array after sorting
/// param[in] array, pointer to it's out-border and sizeof(array type)

/* check error of sorted array */
int check(const void *p, const void *q, size_t nmemb, size_t size)
{
	const char *pb = p;
	const char *qb = q;
	int i;
	for (i = 0; i < nmemb; i++)
		if (*(pb + i*size) != *(qb + i*size))
			return -1;
	return 0;
}


int main()
{
	int E = 0;	// error counting
	
	// list of tests
	int a[6] = {53, -21, 32, 100, -422, 1};
	const int A[6] = {-422, -21, 1, 32, 53, 100};
	
	char b[9] = {'b', 'e', 'c', 'g', 'd', 'i', 'a', 'h', 'f'};
	const char B[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
	
	double c[6] = {-0.2, 0.0, -0.5, 0.3, 0.8, -0.6};
	const double C[6] = {-0.6, -0.5, -0.2, 0.0, 0.3, 0.8};
	
	double d[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	const double D[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	int g[4] = {9999, 999, 99, 9};
	const int G[4] = {9, 99, 999, 9999};
	
	char h[2] = {'i', 'j'};
	const char H[2] = {'i', 'j'};
	
	int m[2] = {7, 3};
	const int M[2] = {3, 7};
	
	int k[5] = {1, 2, 1, 3, 2};
	const int K[5] = {1, 1, 2, 2, 3};
	
	int z[1] = {5};
	const int Z[1] = {5};
	
	/* ----- SORTING ARRAY TEST ----- */
	bsort(a, 6, sizeof(int), int_comp);
	if (check(a, A, 6, sizeof(int)))
		E++;

	bsort(b, 9, sizeof(char), ch_comp);
	if (check(b, B, 9, sizeof(char)))
		E++;
	
	bsort(c, 6, sizeof(double), db_comp);
	if (check(c, C, 6, sizeof(double)))
		E++;
	
	bsort(d, 5, sizeof(double), db_comp);
	if (check(d, D, 5, sizeof(double)))
		E++;

	bsort(g, 4, sizeof(int), int_comp);
	if (check(g, G, 4, sizeof(int)))
		E++;

	bsort(h, 2, sizeof(char), ch_comp);
	if (check(h, H, 2, sizeof(char)))
		E++;

	bsort(m, 2, sizeof(int), int_comp);
	if (check(m, M, 2, sizeof(int)))
		E++;
	
	bsort(k, 5, sizeof(int), int_comp);
	if (check(k, K, 5, sizeof(int)))
		E++;
	
	bsort(z, 1, sizeof(int), int_comp);
	if (check(z, Z, 1, sizeof(int)))
		E++;
	
	printf("\nError found: %d\n", E);		// print number of error
	if (!E)
		printf("\n --- Test result: PASS!\n");
	else
		printf("\n --- Test result: FAIL!\n");
	return 0;
}