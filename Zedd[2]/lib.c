#include <stdio.h>
#include <math.h>
#include "divmem.h"
#include "lib.h"

 
	/* SUM of 2 MATRIXES */
/// \author Binh Nguyen Duc
/// \brief  procedure finds sum of 2 matrixes and print result
/// \details return matrix addition or message of error
/// \param[in] 2 matrixes and its' size

double** addition(double **p, double **q, const int np, const int mp, const int nq, const int mq)
{
	if ((np != nq) || (mp != mq))
		return NULL;
	else
	{
		double** res = allocate_matrix(np, mp);
		if (!res)
			return NULL;
		for (int i = 0; i < np; i++)
		{
			for (int j = 0; j < mp; j++)
				res[i][j] = p[i][j] + q[i][j];	// main
		}
		return res;
	}
}

	/* PRODUCT of 2 MATRIXES */
/// \author Binh Nguyen Duc
/// \brief  procedure finds product of 2 matrixes and print result
/// \details return matrix multiplication or message of error
/// \param[in] 2 matrixes and its' size

double** multiplication(double **p, double **q, const int np, const int mp, const int nq, const int mq)
{
	if (mp != nq)
		return NULL;
	else
	{
		double** res = allocate_matrix(np, mq);
		if (!res)
			return NULL;
		double product;
		for (int i = 0; i < np; i++)
			for (int j = 0; j < mq; j++)
			{
				product = 0;
				for (int k = 0; k < nq; k++)
					product += p[i][k] * q[k][j];	// main
				res[i][j] = product;
			}
		return res;
	}
}

	/* DETERMINANT of SQUARED MATRIX */
/// \author Binh Nguyen Duc
/// \brief  function finds determinant of squared matrix (applying GAUSS's method)
/// \param[in]  matrix and its' size
/// \param[out] determinant value

double Gauss_det(double **A, const int size)
{
	int time = 1;		// time changes (identifying sign of determinant)
	double det = 1;		// set beginning
	
	for (int i = 0; i < size; i++)
	{
		int jmax = i;
		for (int j = i+1; j < size; j++)
			if (fabs(A[j][i]) > fabs(A[jmax][i]))
				jmax = j;		// find max [PIVOT: key by column]
		
		if (A[jmax][i] == 0)
			return 0;
		
		det *= A[jmax][i];		// main
		
		if (jmax != i)			// swap row's pointers
		{
			double *p = A[jmax];
			A[jmax] = A[i];
			A[i] = p;
			time *= (-1);		// change sign
		}
		
		for (int j = i+1; j < size; j++)
		{
			double b = A[j][i] / A[i][i];
			for (int k = i; k < size; k++)		// Gauss's steps
				A[j][k] -= A[i][k] * b;
		}
	}
	return (det * time);
}