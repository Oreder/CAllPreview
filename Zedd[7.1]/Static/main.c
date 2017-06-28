#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/// \author  Binh Nguyen Duc
/// \details Program finds minimum value product of 2 corresponding 
///  		 elements of array, which was read from file.

int main(int argc, char *argv[])
{
	int N;
	FILE *f;
	if (argc < 2)		// check user's command
		printf("Error: Command is not enough variable!\n");
	else
	{
		f = fopen(argv[1], "r");
		if (f)
		{
			if(!read_size(f, &N))	// read number of elements
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
				
					rewind(f);
					read_array(f, a);	// read array
					fclose(f);
					const int *pe = a + N;	// pointer to right border
					print_array(a, pe);  // print array
				
					printf("Minimum value: %d\n", execute(a, pe));
					free(a);			// free memory
				}
			}
			else
				printf("Error: File has something wrong!\n");
		}
		else
			printf("Error: File does not exist!\n");	
	}
	return 0;
}