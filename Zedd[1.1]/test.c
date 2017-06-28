#include <stdio.h>
#include <stdlib.h>
#include "size.h"
#include "read.h"
#include "search.h"

/// \author Binh Nguyen Duc
/// \brief  Module contains all tests for procedures/functions 
/// which are from libraries size.c, read.c and search.c
/// \details function test including file existance, read_size and execute

int main()
{
	int E = 0;
	FILE *f;
	int N;
	printf("\n_____START TESTING...\n\n");
	
	// file's existance test
	f = fopen("test_0.txt", "r");
	if (f) 
		E++;
	
	// reading size tests
	f = fopen("test_1_1.txt", "r");
	if (!read_size(f, &N))
		E++;
	fclose(f);
	
	f = fopen("test_1_2_1.txt", "r");
	if (!read_size(f, &N))
		E++;
	fclose(f);
	
	f = fopen("test_1_2_2.txt", "r");
	if (!read_size(f, &N))
		E++;
	fclose(f);
	
	f = fopen("test_1_2_3.txt", "r");
	if (!read_size(f, &N))
		E++;
	fclose(f);
	
	f = fopen("test_1_3.txt", "r");
	if (!read_size(f, &N))
		E++;
	fclose(f);
	
	f = fopen("test_2.txt", "r");
	read_size(f, &N);
	if (N != 0)
		E++;
	fclose(f);
	
	f = fopen("test_3.txt", "r");
	read_size(f, &N);
	if (N != 1)
		E++;
	fclose(f);
	
	// minimum value test
	const int a[6] = {1, -1, 0, -3, -2, 1};
	const int *p = a + 6;
	if (execute(a, p) != -2)
		E++;
	
	const int b[8] = {-1, -5, -3, -4, -2, -3, -2, -7};
	const int *q = b + 8;
	if (execute(b, q) != 5)
		E++;
	
	const int c[7] = {2, 3, 2, 1, 5, 4, 6};
	const int *r = c + 7;
	if (execute(c, r) != 2)
		E++;
	
	if (E > 0)
		printf("Total test result: FAILED!\n");
	else
		printf("Total test result: SUCCESS!\n");
	
	return 0;
}