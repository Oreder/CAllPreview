#include <stdio.h>
#include "divmem.h"
#include "read.h"

	/* READ MATRIX */
/// \author Binh Nguyen Duc
/// \brief function reads data of matrix from file
/// \param[in] file
/// \param[out] matrix and it's size

double** read_matrix(FILE *f, int *nrow, int *ncol)
{
	if (!fscanf(f, "%d %d", nrow, ncol))		// read size
		return NULL;
		
	if (*nrow < 0 || *ncol < 0)
		return NULL;
	
	double **p = allocate_matrix(*nrow, *ncol);		// allocate dynamic matrix
	if (!p)
		return NULL;
	
	for (int i = 0; i < *nrow; i++)
		for (int j = 0; j < *ncol; j++)
			if (fscanf(f, "%lf", &p[i][j]) != 1)
				return NULL;		// read matrix
	
	return p;
}


	/* PRINT MATRIX TO SCREEN */
/// \author Binh Nguyen Duc
/// \brief procedure prints matrix to screen
/// \param[in] matrix and it's size

void print_to_screen(double** a, const int row, const int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("%10.2f", a[i][j]);
		printf("\n\n");
	}	
}


	/* PRINT MATRIX TO FILE */
/// \author Binh Nguyen Duc
/// \brief procedure prints matrix to file
/// \param[in] file, matrix and it's size

void print_to_file(FILE *f, double** a, const int row, const int column)
{
	fprintf(f, "%d %d\n\n", row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			fprintf(f, "%10.2f", a[i][j]);
		fprintf(f, "\n");
	}	
}


	/* MESSAGES */
/// \author Binh Nguyen Duc
/// \details give messages of errors
/// \param[in] case error

void message(const int i)
{
	switch(i)
	{
		case 1: 
			printf("Error #1: Command has not enough arguments..\n");
			break;
		case 2: 
			printf("Error #2: [I/O] File has something wrong..\n");
			break;
		case 3: 
			printf("Error #3: Memory has not enough to allocate! Exiting..\n");
			break;
		case 4:
			printf("Error #4: Can not count determinant of unsquared matrix\n");
			break;
		case 5: 
			printf("Error #5: Can not open file!\n");
			break;
		case 0:
			printf("Error #0: Commands is not excuted..\n");
			break;
		default:
			getchar();
	}
}	