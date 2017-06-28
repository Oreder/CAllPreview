#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "read.h"
#include "filter.h"
#include "bsort.h"

int main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Error: Command is not enough variable!\n");
	else
	{
		FILE *f = fopen(argv[1], "r");
		if (f)
		{
			int N;
			if (!read_size(f, &N))
			{
				if (N == 0)		// case file contains none elements
					printf("Error: File contain none elements!\n");
			
				if (N == 1)		// case file contains only one element
				printf("Error: File contains not enough elements!\n");
			
				if (N > 1)
				{
					int *a = malloc(N * sizeof(int));	// set length of array
	
					if (a == NULL)		// check memory
					{	
						printf("Exiting program..\n");
						fclose(f);
						exit(0);
					}
				
					rewind(f);			// back to file beginning
					read_array(f, a);	// read array
					fclose(f);			// close input file
					const int *p = a + N;
					print_array(a, p);
					
					if (argc > 3) 
					{	
						char *pstr = argv[3];
						if (pstr[0] == '-' && pstr[1] == 'f')
						{	
							int size = size_out(a, p);
							if (!size)
								printf("Error: None elements satisfied!\n\n");
							else
							{
								int *b = malloc(size * sizeof(int));
								
								if (b == NULL)
								{
									printf("Exiting program..\n");
									exit(0);
								}
								
								get_filter(a, p, b);
								free(a);
								
								bsort(b, size, sizeof(int), int_comp);		// sort array
								
								assert(argv[2] != argv[1]);		// check output filename
								FILE *f = fopen(argv[2], "w");
								fprint_array(f, b, b+size);			// save result to file
								fclose(f);
								
								printf("[Sort] ");
								print_array(b, b+size);
								free(b);
							}
						}
					}
					else
					{
						bsort(a, N, sizeof(int), int_comp);		// sort array
					
						assert(argv[2] != argv[1]);		// check output filename
						FILE *f = fopen(argv[2], "w");
						fprint_array(f, a, p);			// save result to file
						fclose(f);
					
						printf("[Sort] ");
						print_array(a, p);
						free(a);
					}
				}
			}
			else
				printf("Error: File has something wrong!\n");
		}
		else
			printf("Error: [Invalid input] File does not exist!\n");		
	}
	return 0;
}