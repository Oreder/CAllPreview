#include "lib.h"
#include <assert.h>
#include <stdio.h>

/// \author Binh Nguyen Duc
/// \brief  Module uses to read number elements of array from file
/// \param[in]  f - file
/// \param[out] size - number elements

ARR_DLL int __cdecl read_size(FILE *f, int *size)
{
	int x;
	*size = 0; 
	while (fscanf(f, "%d", &x) == 1)
		(*size)++;
	
	if (feof(f))
		return 0;
	else
		return -1;
}

/// \author Binh Nguyen Duc
/// \brief  Module uses to read array from file and print array
/// \param[in]  f - file
/// \param[out] array[size]

/* function reads array from file */
ARR_DLL int __cdecl read_array(FILE *f, int *a)
{
	while (fscanf(f, "%d", a) == 1)
		a++;
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  Module uses to print out all elements of input array
/// \param[in]  const array a and const pointer to right border of arrays

/* function prints out array */
ARR_DLL int __cdecl print_array(const int *a, const int *pe)
{
	printf("Array:");
	const int *p;
	for (p = a; p < pe; p++)
		printf(" %d", *p);
	printf("\n\n");
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief module finds MIN value of a[0]*a[1], a[1]*a[2],..., a[N-2]*a[N-1]
///  where a - const array. Use library "search.h"
/// \param[in] a - array, pe - pointer to right border
/// \param[out] minimum value

ARR_DLL int __cdecl execute(const int *a, const int *pe)	// main
{
	assert(pe - a >= 2); // check number elements
	int best, cur;
	const int *p;
	p = pe-1;
	best  = *p;
	best *= *(p-1);
	
	for(p = pe - 1; p > a; p--)
	{
		cur = *p; cur *= *(p-1);
		best = (best < cur)? best : cur;	// count min
	}
	return best;
}