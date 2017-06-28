#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// type of exported functions from .dll
typedef int (__cdecl *func_read_t)(FILE *, int *);
typedef int (__cdecl *func_exe_t)(const int *, const int *);

/// \author  Binh Nguyen Duc
/// \details Program finds minimum value product of 2 corresponding 
///  		 elements of array, which was read from file.

int main(int argc, char *argv[])
{
	HMODULE LIB;
	func_read_t read_size, read_array;
	func_exe_t  print_array, execute;
	
	// search .DLL library
	LIB = LoadLibrary(TEXT("arr.dll"));
	if (!LIB)
	{
		printf("Error #1: Library can not load! Exiting..\n");
		return -1;
	}
	
	int N;
	FILE *f;
	if (argc < 2)		// check user's command
		printf("Error #3: Command is not enough variable!\n");
	else
	{
		f = fopen(argv[1], "r");
		if (f)
		{
			read_size = (func_read_t) GetProcAddress(LIB, "read_size");
			if (!read_size)
			{
				printf("Error #2: Can not load function!\n");
				fclose(f);
				FreeLibrary(LIB);
				return -2;
			}
			
			if(read_size(f, &N))	// read number of elements
			{
				printf("Error #3: File has something wrong!\n");
				fclose(f);
			}
			else
			{	
				if (N == 0)		// case file contains none elements
					printf("Error: File contain none elements!\n");
			
				if (N == 1)		// case file contains only one element
				printf("Error: File contains not enough elements!\n");
			
				if (N > 1)
				{
					read_array = (func_read_t) GetProcAddress(LIB, "read_array");
					if (!read_array)
					{
						printf("Error #2: Can not load function!\n");
						FreeLibrary(LIB);
						fclose(f);
						return -2;
					}
					
					int *a = malloc(N * sizeof(int));	// set length of array
	
					if (a == NULL)		// check memory
					{	
						printf("Error #4: Lack of memmory! Exiting..\n");
						fclose(f);
						FreeLibrary(LIB);
						exit(4);
					}
					
					rewind(f);
					read_array(f, a);	// read array
					fclose(f);
					const int *pe = a + N;	// pointer to right border
					
					print_array = (func_exe_t) GetProcAddress(LIB, "print_array");
					if (!print_array)
					{
						printf("Error #2: Can not load function!\n");
						fclose(f);
						free(a);			// free memory
						FreeLibrary(LIB);
						return -2;
					}
					print_array(a, pe);  // print array
					
					execute = (func_exe_t) GetProcAddress(LIB, "execute");
					if (!execute)
					{
						printf("Error #2: Can not load function!\n");
						fclose(f);
						free(a);			// free memory
						FreeLibrary(LIB);
						return -2;
					}
					
					printf("Minimum value: %d\n", execute(a, pe));
					free(a);			// free memory
				}
			}
		}
		else
			printf("Error #3: File does not exist!\n");	
	}
	
	FreeLibrary(LIB);
	return 0;
}