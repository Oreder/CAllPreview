#include <stdio.h>
#include "read.h"

/// \author Binh Nguyen Duc
/// \brief  Module uses to read array from file and print array
/// \param[in]  f - file
/// \param[out] array[size]

/* function reads array from file */
int read_array(FILE *f, int *a)
{
	while (fscanf(f, "%d", a) == 1)
		a++;
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  Module uses to print out all elements of input array
/// \param[in]  const array a and const pointer to right border of arrays

/* function prints out array */
int print_array(const int *a, const int *pe)
{
	printf("Array:");
	const int *p;
	for (p = a; p < pe; p++)
		printf(" %d", *p);
	printf("\n\n");
	return 0;
}