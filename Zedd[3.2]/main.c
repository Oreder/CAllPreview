	/* ----- MAIN ----- */
/// \author  Binh Nguyen Duc
/// \brief   String (C) implemetation
/// \details Using functions in libraries "lib.h", "rep.h" and "err.h"

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"	/*     READ FILE    */
#include "rep.h"	/* FIND AND REPLACE */
#include "err.h"	/*  ERROR MESSAGES  */

#define ERROR_1 1	/*  COMMAND ERRORS  */
#define ERROR_2 2	/*    I/O ERRORS    */
#define ERROR_3 3	/*  MEMORY  ERRORS  */

int main(int argc, char *argv[])
{
	if (argc < 5)
		message(1);
	else
	{
		FILE *f = fopen(argv[1], "r");
		if (!f)		// check input file
		{
			message(2);
			return ERROR_2;
		}
		
		FILE *g = fopen(argv[2], "w");
		if (!g)		// check output file
		{
			message(2); fclose(f);
			return ERROR_2;
		}
		
		if ((argv[3][0] != '-') && (argv[3][1] != 'r'))
		{
			message(1); 		// "-r": executation signal
			fclose(f); fclose(g);
			return ERROR_1;
		}
		
		char *find = argv[4];	// string to find
		char *rep;				// string to replace
		if (argc == 5)
			rep = "";			// case: EMPTY  string
		else
			rep = argv[5];		// case: normal string
		
		char *line;				// line as source string
		
		while (!feof(f))
		{
			line = get_line(f);	// read line
			
			if (!line || length(line) == 1)
				fprintf(g, "\n");
			else
			{
				char *tmp = replace(line, find, rep);	// replace string
				
				if (!tmp)
				{
					message(3);		// memory out
					free(line);
					fclose(f); fclose(g);
					return ERROR_3;		
				}
				
				fsave(g, tmp);		// save working string to file
				free(tmp);			// free working string
			}
			
			free(line);		// free working line
		}
		
		fclose(f); fclose(g);
	}
	
	return 0;
}
