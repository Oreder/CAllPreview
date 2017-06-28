/* ----- READ/PRINT module ----- */

#include <stdio.h>
#include "read.h"

/// \author Binh Nguyen Duc
/// \brief  function reads number elements of array from file
/// \param[in]  f - file
/// \param[out] size - number elements

/* reading number elements of array */
int read_size(FILE *f, int *size)
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
/// \brief  procedure reads array from file and print array
/// \param[in]  f - file
/// \param[out] array[size]

/* procedure reads array from file */
int read_array(FILE *f, int *a)
{
	while (fscanf(f, "%d", a) == 1)
		a++;
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  procedure prints out elements of input array
/// \param[in] array and pointer to right border of arrays

/* procedure prints out array */
int print_array(const int *a, const int *pe)
{
	printf("Array:");
	const int *p;
	for (p = a; p < pe; p++)
		printf(" %d", *p);
	printf("\n\n");
	return 0;
}


/// \author Binh Nguyen Duc
/// \brief  procedure prints out elements of input array
/// \param[in] file, array and pointer to right border of arrays

/* procedure prints array to file */
int fprint_array(FILE *f, const int *a, const int *pe)
{
	const int *r;
	for (r = a; r < pe; r++)
		fprintf(f, "%d ", *r);
	return 0;
}