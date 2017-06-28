#include <stdio.h>
#include "read.h"

int main()
{
	int err = 0, col, row;
	FILE *f;
	const int a[5] = {0, 214783647, -12, 100, -9};
		//  [1][5] = {{0, 214783647, -12, 100, -9}}
	const int b[6] = {1, -2, 3, -4, 5, -67};
		//  [2][3] = {{1, -2, 3}, {-4, 5, -67}};
	const int c[6] = {0, 0, -171, 214783647, 214783647, 9302};	
		//  [2][3] = {{0, 0}, {-171, 214783647},{214783647, 9302}}
	const int d[6] = {0, 214783647, 214783647, 0, 214783647, -214783650};	//[6][1]
	const int e[3] = {214783647, 214783647, -214783647};
		//  [3][1] = {{214783647}, {214783647}, {-214783647}}
	
	/* test size */
	f = fopen("0.txt", "r");
	if (!read_size(f, &col, &row))
		err++;
	fclose(f);
	
	f = fopen("1.txt", "r");
	read_size(f, &col, &row);
	if (row != 1 && col != 5)
		err++;
	fclose(f);
	
	f = fopen("2.txt", "r");
	read_size(f, &col, &row);
	if (row != 2 && col != 3)
		err++;
	fclose(f);
	
	/* read matrix test */
	f = fopen("1.txt", "r");
	int A[5];
	read_matrix(f, A);
	fclose(f);
	for (int i = 0; i < 5; i++)
		if (*(a+i) != *(A+i))
			err++;
	
	f = fopen("2.txt", "r");
	int B[6];
	read_matrix(f, B);
	fclose(f);
	for (int i = 0; i < 6; i++)
		if (*(b+i) != *(B+i))
			err++;
	
	f = fopen("3.txt", "r");
	int C[6];
	read_matrix(f, C);
	fclose(f);
	for (int i = 0; i < 6; i++)
		if (*(c+i) != *(C+i))
			err++;
	
	f = fopen("4.txt", "r");
	int D[6];
	read_matrix(f, D);
	fclose(f);
	for (int i = 0; i < 6; i++)
		if (*(d+i) != *(D+i))
			err++;
		
	f = fopen("5.txt", "r");
	int E[3];
	read_matrix(f, E);
	fclose(f);
	for (int i = 0; i < 3; i++)
		if (*(e+i) != *(E+i))
			err++;

	if (err == 0)
		printf("Test result: PASS!\n");
	else
		printf("Test result: FAIL!\n");
	
	return 0;
}