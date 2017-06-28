#include <stdio.h>
#include "size.h"

/// \author Binh Nguyen Duc
/// \brief  Module uses to read number elements of array from file
/// \param[in]  f - file
/// \param[out] size - number elements

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