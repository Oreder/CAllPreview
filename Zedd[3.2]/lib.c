#include <stdlib.h>	/* malloc, realloc, free */
#include <stdio.h>	/* fopen, fgetc, fclose  */
#include "rep.h"	/* length */
#include "lib.h"

	
#define EOL '\n'			/* END OF LINE  */
#define defaut_size 5		/* Default size */


/// \author Binh Nguyen Duc
/// \brief  Reads the line. If successful, returns a pointer to the line,
///         and sets *len to the number of characters. The result
///		    is a C string; it has terminating '\0'. The returned pointer
///		    remains valid until the next call to get_line().
/// \details get_line() returns NULL at end of file or if there is an error with 
/// 		 memory allocation.

	/* READ LINE FROM FILE */
char *get_line(FILE *f)
{
	char *line = NULL;
	int size = 0, buf_size;
	char buf[defaut_size];		/* Const buffer */
	
	while ((fgets(buf, defaut_size, f) != NULL))
	{
		buf_size = length(buf);		/* Real size need allocating more */
		
		if (size == 0)				/* Case: line is not allocated */
		{
			line = malloc((buf_size + 1) * sizeof(char));
			if (!line)
				return NULL;
			size = buf_size;
		}
		else
		{
			size += buf_size;		/* Case: line need reallocating */
			char *temp = realloc(line, ((size + 1) * sizeof(char)));
			if (!temp)
				return NULL;
			line = temp;			/* Save line */
		}
		
		for (int i = 0; i <= buf_size; i++)		/* Copy buffer to allocated part */
			line[size - buf_size + i] = buf[i];
		
		if ((line[size - 1] == EOL))
			return line;
	}
	
	return line;
}	
