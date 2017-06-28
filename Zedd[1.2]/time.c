#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>
#include "bsort.h"

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
int random_array(int *a, int *b, const int nmemb, const int low, const int high)
{
	for (int i = 0; i < nmemb; i++)
	{
		a[i] = random_number(low, high);
		b[i] = a[i];
	}
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  procedure gets array in ascending
/// param[in] nmemb - number members of array
/// param[out] randomized arrays

/* ascending */
int random_array_1(int *a, int *b, const int nmemb)
{
	for (int i = 0; i < nmemb; i++)
	{
		a[i] = i;
		b[i] = a[i];
	}
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  procedure gets array in decending
/// param[in] nmemb - number members of array
/// param[out] randomized arrays

/* decending */
int random_array_2(int *a, int *b, const int nmemb)
{
	for (int i = 0; i < nmemb; i++)
	{
		a[i] = -i;
		b[i] = a[i];
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
		
		random_array(a, b, k, -100, 100);		// random array with range
		
		tb = tick();
		qsort(a, k, sizeof(int), int_comp);
		te = tick();
		free(a);
		printf("%llu\t", te-tb);
		
		tb = tick();
		bsort(b, k, sizeof(int), int_comp);
		te = tick();
		free(b);
		printf("%llu\t\n", te-tb);
	}
	
	printf("\n");
	
	for (int k = 2; k < N; k++)
	{
		printf("%d\t", k);
		int *a = malloc(k * sizeof(int));
		int *b = malloc(k * sizeof(int));
		
		random_array_1(a, b, k);			// ascending array
		
		tb = tick();
		qsort(a, k, sizeof(int), int_comp);
		te = tick();
		free(a);
		printf("%llu\t", te-tb);
		
		tb = tick();
		bsort(b, k, sizeof(int), int_comp);
		te = tick();
		free(b);
		printf("%llu\t\n", te-tb);
	}
	
	printf("\n");
	
	for (int k = 2; k < N; k++)
	{
		printf("%d\t", k);
		int *a = malloc(k * sizeof(int));
		int *b = malloc(k * sizeof(int));
		
		random_array_2(a, b, k);			// decending array
		
		tb = tick();
		qsort(a, k, sizeof(int), int_comp);
		te = tick();
		free(a);
		printf("%llu\t", te-tb);
		
		tb = tick();
		bsort(b, k, sizeof(int), int_comp);
		te = tick();
		free(b);
		printf("%llu\t\n", te-tb);
	}
	
	return 0;
}