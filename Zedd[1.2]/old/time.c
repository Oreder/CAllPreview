#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>
#include "sort.h"

unsigned long long tick(void)
{
	unsigned long long d;
	__asm__ __volatile__ ("rdtsc" : "=A" (d) );
	return d;
}

/// \author Binh Nguyen Duc
/// \brief  function gets random number in range
/// param[in] min_num, max_num - ranges

/* random number in range */
int random_number(int min_num, int max_num)
{
    //assert(max_num - min_num > 0);
	return (rand() % (max_num-min_num)) + min_num;
}

/// \author Binh Nguyen Duc
/// \brief  procedure randomizes array in range
/// param[in] nmemb - number members of array, low, high - random ranges
/// param[out] randomized array

/* randomize array */
int random_array(int *a, int *b, int *c, const int nmemb, const int low, const int high)
{
	for (int i = 0; i < nmemb; i++)
	{
		a[i] = random_number(low, high);
		b[i] = a[i];
		c[i] = a[i];
	}
	return 0;
}


#define N 20

int main(void)
{
	unsigned long long tb, te;
	
	for (int k = 1; k < N; k++)
	{
		printf("%d\t", k);
		int *a = malloc(k * sizeof(int));
		int *b = malloc(k * sizeof(int));
		int *c = malloc(k * sizeof(int));
		
		random_array(a, b, c, k, -100, 100);		// random array with range
		
		tb = tick();
		qsort(a, k, sizeof(int), int_comp);
		te = tick();
		free(a);
		printf("%llu\t", te-tb);
		
		tb = tick();
		bsort(b, k, sizeof(int), int_comp);
		te = tick();
		free(b);
		printf("%llu\t", te-tb);
		
		tb = tick();
		osort(c, k, sizeof(int), int_comp);
		te = tick();
		free(c);
		printf("%llu\t\n", te-tb);
	}
	
	return 0;
}