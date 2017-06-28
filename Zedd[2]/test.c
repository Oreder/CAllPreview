/* ----- TESTS ----- */
/// \author Binh Nguyen Duc
/// \details modulo tests functions with matrixes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "divmem.h"
#include "lib.h"

#define eps 1E-9

	/* DIFF(double, double) */
/// \author Binh Nguyen Duc
/// \brief funtion compares 2 long numbers (double)
/// \details return 0 of no different found or 1 if they are different

int diff(double a, double b)
{
	double value = fmax(fabs(a), fabs(b));		// define maximum absolute value
	if (value < 1)		// case 2 numbers are in range (-1, 1)
		value = eps;
	else
		value *= eps;	// other cases
	
	if (fabs(a - b) <= value)
		return 0;	// no error
	else 
		return 1;	// error
}

	
	/* ADDITION 2 matrixes test */
/// \author Binh Nguyen Duc
/// \details testing addition() in "lib.h", return number of errors

int ADD_test()
{
	printf("\n#       ADDITION: ");
	int err = 0;		// error counting
	
	double **a = allocate_matrix(1, 5);
	for (int i = 0; i < 5; i++) a[0][i] = i+1;
	
	double **b = allocate_matrix(2, 4);
	b[0][0] = 0; b[0][1] = -12; b[0][2] = -345; b[0][3] = -6789;
	b[1][0] = 9; b[1][1] = 87; b[1][2] = 654; b[1][3] = 3210;
	
	double **d = allocate_matrix(2, 4);
	d[0][0] = 0; d[0][1] = 10; d[0][2] = -155; d[0][3] = 6790;
	d[1][0] = 0; d[1][1] = 13; d[1][2] = -454; d[1][3] = -10;
	
	double **c = allocate_matrix(3, 3);
	c[0][0] = 0; c[0][1] = 1; c[0][2] = 0;
	c[1][0] = 1; c[1][1] = 0; c[1][2] = 0;
	c[2][0] = 0; c[2][1] = 0; c[2][2] = 1;
	
	double **f = allocate_matrix(3, 3);
	f[0][0] = 1; f[0][1] = 0; f[0][2] = 1;
	f[1][0] = 0; f[1][1] = 1; f[1][2] = 1;
	f[2][0] = 1; f[2][1] = 1; f[2][2] = 0;
	
	double A[1][5] = {{2, 4, 6, 8, 10}};
	double BD[2][4] = {{0, -2, -500, 1}, {9, 100, 200, 3200}};
	double CF[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
	
	double **sum;
	
	sum = addition(a, b, 1, 5, 2, 4);
	if (sum != NULL) 
		err++;
	
	sum = addition(a, a, 1, 5, 1, 5);
	for (int i = 0; i < 5; i++)
		if (diff(sum[0][i], A[0][i])) err++;
	free(a); free(sum);
	
	sum = addition(b, d, 2, 4, 2, 4);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			if (diff(sum[i][j], BD[i][j])) err++;
	free(b); free(d); free(sum);
	
	sum = addition(c, f, 3, 3, 3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (diff(sum[i][j], CF[i][j])) err++;
	free(c); free(f); free(sum);

	if (err > 0)		// result
		printf("Total error: %d\t__result: FAILED!\n", err);
	else
		printf("Total error: 0\t__result: PASSED!\n");
	
	return err;
}


	/* MULTIPLICATION 2 matrixes test */
/// \author Binh Nguyen Duc
/// \details testing multiplication() in "lib.h", return number of errors

int PRO_test()
{
	printf("\n# MULTIPLICATION: ");
	int err = 0;		// error counting
	
	double **a_1 = allocate_matrix(1, 5);
	for (int i = 0; i < 5; i++) a_1[0][i] = i+1;
	
	double **b_1 = allocate_matrix(5, 1);
	for (int i = 0; i < 5; i++) b_1[i][0] = i+1;
	
	double A[1][1] = {{55}};	// SIZE 1x1
	
	double **b_2 = allocate_matrix(5, 2);
	b_2[0][0] = 0; b_2[0][1] = 9; 
	b_2[1][0] = 1; b_2[1][1] = 8; 
	b_2[2][0] = 2; b_2[2][1] = 7;
	b_2[3][0] = 3; b_2[3][1] = 6; 
	b_2[4][0] = 4; b_2[4][1] = 5;
	
	double B[1][2] = {{40, 95}};	// SIZE 1x2
	
	double **a_2 = allocate_matrix(2, 4);
	a_2[0][0] = 0; a_2[0][1] = -12; a_2[0][2] = -345; a_2[0][3] = -6789;
	a_2[1][0] = 9; a_2[1][1] = 87; a_2[1][2] = 654; a_2[1][3] = 3210;
	
	double **b_3 = allocate_matrix(4, 3);
	b_3[0][0] = 2; b_3[0][1] = 0; b_3[0][2] = -1;
	b_3[1][0] = 0; b_3[1][1] = 1; b_3[1][2] = 1;
	b_3[2][0] = 1; b_3[2][1] = 0; b_3[2][2] = 0;
	b_3[3][0] = 0; b_3[3][1] = 0; b_3[3][2] = 0;
	
	double C[2][3] = {{-345, -12, -12}, {672, 87, 78}};		// SIZE 2x3
	
	double **c_1 = allocate_matrix(3, 3);
	c_1[0][0] = 1; c_1[0][1] = 0; c_1[0][2] = 0;
	c_1[1][0] = 0; c_1[1][1] = 1; c_1[1][2] = 0;
	c_1[2][0] = 0; c_1[2][1] = 0; c_1[2][2] = 1;
	
	double **c_2 = allocate_matrix(3, 3);
	c_2[0][0] = 1; c_2[0][1] = 2; c_2[0][2] = 3;
	c_2[1][0] = 4; c_2[1][1] = 5; c_2[1][2] = 6;
	c_2[2][0] = 7; c_2[2][1] = 8; c_2[2][2] = 9;
	
	double c_0[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};	// SIZE 3x3
	
	double **pro = multiplication(a_1, b_1, 1, 5, 5, 1);
	if (diff(pro[0][0], A[0][0])) err++;
	free(b_1); free(pro);
	
	pro = multiplication(a_1, c_2, 1, 5, 3, 3);
	if (pro != NULL)
		err++;
	
	pro = multiplication(a_1, b_2, 1, 5, 5, 2);
	if ((diff(pro[0][0], B[0][0])) || (diff(pro[0][1], B[0][1]))) err++;
	free(a_1); free(b_2); free(pro);
	
	pro = multiplication(a_2, b_3, 2, 4, 4, 3);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			if (diff(pro[i][j], C[i][j])) err++;
	free(a_2); free(b_3); free(pro);

	pro = multiplication(c_1, c_2, 3, 3, 3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (diff(pro[i][j], c_0[i][j])) err++;
	free(c_1); free(c_2); free(pro);
	
	if (err > 0)		// result
		printf("Total error: %d\t__result: FAILED!\n", err);
	else
		printf("Total error: 0\t__result: PASSED!\n");
	
	return err;	
}


	/* DETERMINANT of matrix test */
/// \author Binh Nguyen Duc
/// \details testing Gauss_det() in "lib.h", return number of errors

int DET_test()
{
	printf("\n#    DETERMINANT: ");
	int err = 0;		// error counting
	
	double **A = allocate_matrix(1, 1);		// SIZE = 1
	A[0][0] = 1;
	double detA = 1;
	if (diff(detA, Gauss_det(A, 1))) err++;
	free(A);
	
	double **B = allocate_matrix(2, 2);		// SIZE = 2 (E)
	B[0][0] = 1; B[0][1] = 0; 
	B[1][0] = 0; B[1][1] = 1;
	double detB = 1;
	if (diff(detB, Gauss_det(B, 2))) err++;
	free(B);
	
	double **C = allocate_matrix(3, 3);		// SIZE = 3 (max)
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			C[i][j] = 999999999;
	double detC = 0;
	if (diff(detC, Gauss_det(C, 3))) err++;
	free(C);
	
	double **E = allocate_matrix(3, 3);		// SIZE = 3 (column)
	E[0][0] = 5; E[0][1] = -10; E[0][2] = 4;
	E[1][0] = 1; E[1][1] = -2; E[1][2] = 2;
	E[2][0] = 3; E[2][1] = -6; E[2][2] = 9;
	double detE = -0;
	if (diff(detE, Gauss_det(E, 3))) err++;
	free(E);
	
	double **F = allocate_matrix(3, 3);		// SIZE = 3 (row)
	F[0][0] = 1; F[0][1] = 2; F[0][2] = 4;
	F[1][0] = 1; F[1][1] = 2; F[1][2] = 4;
	F[2][0] = 3; F[2][1] = 4; F[2][2] = 9;
	double detF = 0;
	if (diff(detF, Gauss_det(F, 3))) err++;
	free(F);
	
	double **G = allocate_matrix(3, 3);		// SIZE = 3 (row)
	G[0][0] = -5; G[0][1] = 3; G[0][2] = 7;
	G[1][0] = 6; G[1][1] = -2; G[1][2] = 2;
	G[2][0] = 1; G[2][1] = 1; G[2][2] = 9;
	double detG = 0;
	if (diff(detG, Gauss_det(G, 3))) err++;
	free(G);
	
	double **M = allocate_matrix(3, 3);		// SIZE = 3 (normal)
	M[0][0] = 1; M[0][1] = 2; M[0][2] = 3;
	M[1][0] = 4; M[1][1] = 5; M[1][2] = 6;
	M[2][0] = 7; M[2][1] = 8; M[2][2] = 10;
	double detM = -3;
	if (diff(detM, Gauss_det(M, 3))) err++;
	free(M);
	
	double **H = allocate_matrix(4, 4);		// SIZE = 4 (matrix O)
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			H[i][j] = 0;
	double detH = 0;
	if (diff(detH, Gauss_det(H, 4))) err++;
	free(H);
	
	double **D = allocate_matrix(4, 4);		// SIZE = 4 (normal)
	D[0][0] = 1; D[0][1] = 2; D[0][2] = 3; D[0][3] = 4;
	D[1][0] = 2; D[1][1] = 3; D[1][2] = 4; D[1][3] = 1;
	D[2][0] = 3; D[2][1] = 4; D[2][2] = 1; D[2][3] = 2;
	D[3][0] = 4; D[3][1] = 1; D[3][2] = 2; D[3][3] = 3;
	double detD = 160;
	if (diff(detD, Gauss_det(D, 4))) err++;
	free(D);
	
	double **I = allocate_matrix(4, 4);		// SIZE = 4 (normal)
	I[0][0] = 5; I[0][1] = 5; I[0][2] = 3; I[0][3] = 1;
	I[1][0] = 0; I[1][1] = 2; I[1][2] = 2; I[1][3] = 7;
	I[2][0] = 6; I[2][1] = 1; I[2][2] = 1; I[2][3] = 3;
	I[3][0] = 4; I[3][1] = 0; I[3][2] = 0; I[3][3] = 0;
	double detI = 8;
	if (diff(detI, Gauss_det(I, 4))) err++;
	free(I);
	
	
	double **K = allocate_matrix(5, 5);		// SIZE = 5
	K[0][0] = 1; K[0][1] = 2; K[0][2] = 2; K[0][3] = 2; K[0][4] = 2;
	K[1][0] = 2; K[1][1] = 1; K[1][2] = 2; K[1][3] = 2; K[1][4] = 2;
	K[2][0] = 2; K[2][1] = 2; K[2][2] = 1; K[2][3] = 2; K[2][4] = 2;
	K[3][0] = 2; K[3][1] = 2; K[3][2] = 2; K[3][3] = 1; K[3][4] = 2;
	K[4][0] = 2; K[4][1] = 2; K[4][2] = 2; K[4][3] = 2; K[4][4] = 1;
	double detK = 9;
	if (diff(detK, Gauss_det(K, 5))) err++;
	free(K);	
	
	if (err > 0)		// result
		printf("Total error: %d\t__result: FAILED!\n", err);
	else
		printf("Total error: 0\t__result: PASSED!\n");
	
	return err;
}


	/* MAIN */
int main()
{
	printf("\n______TESTs for LIB.H\n");
	
	int total = ADD_test();
	total += PRO_test();
	total += DET_test();
	
	if (total == 0)
		printf("\n_____RESULT: OK!\n");
	else
		printf("\n_____RESULT: ERROR!\n");
	return 0;
}