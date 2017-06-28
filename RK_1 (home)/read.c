#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "limits.h"

	/* function finds size of matrix */
int read_size(FILE *f, int *ncol, int *nrow)
{
	char *buf = malloc(ROW_MAX * sizeof(char));
	
	while (fgets(buf, ROW_MAX, f))
		if (*buf != '\n')
			break;			// get first row

	*ncol = 0;
	if (buf[0] != ' ')
		*ncol = 1;
	
	for (int i = 1; buf[i] != '\0'; i++)
		if ((buf[i-1] == ' ') && (buf[i] != ' '))
			(*ncol)++;		// get number elements in each row
	
	if (*ncol == 0)
	{
		free(buf);
		return -1;			// error line
	}	
	else
	{
		*nrow = 1;
		while (fgets(buf, ROW_MAX, f))
			if (*buf != '\n')
				(*nrow)++;		// get number of rows
	}
	
	free(buf);
	return 0;
}

	/* function reads matrix from file */
int read_matrix(FILE *f, int *p)
{
	char *buf = malloc(ROW_MAX * sizeof(char));
	
	while (fgets(buf, ROW_MAX, f))
	{	
		int str_len = strlen(buf) - 1;
		if (feof(f))
			str_len++;
		
		if (str_len > 0)
		{
			int i = 0;
			while (i < str_len)				// while not end of line
			{	
				if (buf[i] != ' ')			// read char
				{
					int sign = 1;
					if (buf[i] == '-')		// identify sign
					{
						sign = -1;
						i++;
					}
					
					int x = 0, err = 0;					
					while (i < str_len && buf[i] != ' ')
					{
						if (buf[i] < '0' || buf[i] > '9')
							err++;
						else
							x = 10 * x + (buf[i] - '0');
						i++;
					}
					
					if (err)
						*p = INT_MAX;
					else
						*p = x * sign;
					p++;	
				}
				i++;
			}
		}
	}
	
	free(buf);
	
	return 0;
}


		/* function prints matrix */
int print_matrix(const int *p, const int size, const int ncol)
{
	for (int i = 0; i < size; i++)
	{	
		if (i % ncol == 0)
			printf("\n");
		printf("|%10d|", *(p + i));
	}
		
	return 0;
}