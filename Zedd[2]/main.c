	/* ------ MAIN ------ */
/// \author Binh Nguyen Duc
/// \details program with matrixes 

#include <stdio.h>
#include <stdlib.h>
#include "divmem.h"
#include "read.h"
#include "lib.h"
	
int main(int argc, char **argv)
{
	if ((argc > 1) && (argv[1][0] == '-'))		// get signal
	{
		if ((argv[1][1] == 's') || (argv[1][1] == 'p'))
		{
			
			if (argc < 5)
			{
				message(1);
				return -1;
			}
			
			FILE *f = fopen(argv[2], "r");
			if (!f)				// [I/O] check FILEs' error
			{
				message(2); 
				return -2;
			}
			
			FILE *g = fopen(argv[3], "r");
			if (!g)				// [I/O] check FILEs' error
			{
				message(2);
				return -2;
			}
			
			int arow, acol, brow, bcol;		// read matrixes
			double **a = read_matrix(f, &arow, &acol);
			double **b = read_matrix(g, &brow, &bcol);
			fclose(f); fclose(g);
			
			if ((!a) || (!b))
			{
				message(3);
				free(a); free(b);
				return -3;
			}
			
			printf("# Matrix 1:\n\n"); print_to_screen(a, arow, acol);
			printf("# Matrix 2:\n\n"); print_to_screen(b, brow, bcol);
			
			double **c;
			if (argv[1][1] == 's')		// signal "-s": (result) SUM
				c = addition(a, b, arow, acol, brow, bcol);
			
			if (argv[1][1] == 'p')		// signal "-p": (result) PRODUCT
				c = multiplication(a, b, arow, acol, brow, bcol);
			
			free(a); free(b);
			
			if (!c)
			{
				message(0);
				free(c);
				return 0;
			}
			
			printf("# Result:\n\n"); 
			print_to_screen(c, arow, bcol);
			
			f = fopen(argv[4], "w");
			if (!f)
			{
				message(5);
				free(c);
				return -5;
			}	
			
			print_to_file(f, c, arow, bcol);
			fclose(f);
			free(c);
		}
		else if (argv[1][1] == 'd')		// signal "-d": (result) DETERMINANT
		{
			if (argc < 3)
			{
				message(1);
				return -1;
			}
			
			FILE *f = fopen(argv[2], "r");
			if (!f)			// [I/O] check file's error
			{
				message(2);
				return -2;
			}
			
			int row, col;		// read matrix
			double **p = read_matrix(f, &row, &col);
			fclose(f);
			
			if (!p)
			{
				message(3);
				free(p);
				return -3;
			}
			
			printf("# Matrix:\n\n"); print_to_screen(p, row, col);
			
			if (row == col)		// question squared matrix or not
				printf("# Determinant: %.2f\n", Gauss_det(p, row));
			else
				message(4);
			free(p);
		}
		else
			printf("Error #6: Unidentified structure '%s'\n", argv[1]);
	}
	else
		printf("Error #0: Commands were unexecuted..\n");
	
	return 0;
}