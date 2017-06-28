#include <stdio.h>
#include <stdlib.h>
#include "divmem.h"

	/* ALLOCATE MATRIX */
/// \author Binh Nguyen Duc
/// \brief function allocate dynamic matrix (TYPE 3)
/// \param[in] matrix's size

double** allocate_matrix(int nrow, int ncol)
{	
	double **p = malloc(nrow * sizeof(double *) + nrow * ncol * sizeof(double));
    if (!p)
        return NULL;
	
	for(int i = 0; i < nrow; i++)		// allocate elements
        p[i] = (double *)((char *)p + nrow * sizeof(double *) + i * ncol * sizeof(double));
	
	return p;
}