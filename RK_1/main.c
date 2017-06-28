/* Variant 3 */
#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Error: No file name!\n");
		return 0;
	}
	
	FILE *f = fopen(argv[1], "r");
	if (!f)
	{
		printf("Error: File is not found!\n");
		return 0;
	}
	
	int m, n;
	read_size(f, &m, &n);
	
	int **a = malloc(m * n * sizeof(int));
	if (a == NULL)
	{
		printf("Error: Exiting program..\n");
		fclose(f);
		return 0;
	}
	
	int *p = *a;
	int size = m*n;
	rewind(f);
	read_matrix(f, p, size);
	fclose(f);
	
	p = *a;
	printf("Matrix: \n");
	print_matrix(p, m, n);
	free(a);
	return 0;
}