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
	if (read_size(f, &m, &n))
	{
		printf("Error: File has no elements!\n");
		fclose(f);
		return 0;
	}
	
	printf("C: %d, R: %d\n", m, n);
	int *a = malloc(m * n * sizeof(int));
	if (a == NULL)
	{
		printf("Error: Exiting program..\n");
		fclose(f);
		return 0;
	}
	
	rewind(f);
	read_matrix(f, a);
	fclose(f);
	
	print_matrix(a, m*n, m);
	free(a);
	return 0;
}