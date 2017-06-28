#include <stdio.h>
#include "read.h"
#include "limits.h"

int read_size(FILE *f, int *ncol, int *nrow)
{
	*nrow = 0;
	int c, x, total = 0;
	while ((c = fgetc(f)) != '\n' && (c != EOF))
	{	
		ungetc(c, f);
		if (fscanf(f, "%d", &x))
			(*nrow)++;
	}
	
	if (!feof(f))
	{
		rewind(f);
		while (fscanf(f, "%d", &x) == 1)
			total++;	
		*ncol = total / *nrow;
	}	
	else
	{
		if (*nrow != 0)
			*ncol = 1;
		else
			return -1;
	}
	return 0;
}


int read_matrix(FILE *f, int *p, const int size)
{
	for (int i = 0; i < size; i++)
		fscanf(f, "%d", p + i);
	return 0;
}


int print_matrix(int *a, int ncol, int nrow)
{
	for (int i = 0; i < ncol; i++)
	{
		for (int j = 0; j < nrow; j++)
			printf("%d ", *(a + j + i*nrow));
		printf("\n");
	}
	return 0;
}