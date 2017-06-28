#include <stdlib.h>	/* malloc, realloc, free */
#include <stdio.h>	/* fopen, fgetc, fclose  */
#include "lib.h"

/// \author Binh Nguyen Duc
/// \brief  Initializes a line_reader lr for the stream f
	
	/* INITIALIZE */
void lr_init(struct line_reader *lr, FILE *f)
{
	lr->f = f;
	lr->buf = NULL;
	lr->siz = 0;
}

/// \author Binh Nguyen Duc
/// \brief  Reads the line. If successful, returns a pointer to the line,
///         and sets *len to the number of characters, at least 1. The result
///		    is not a C string; it has no terminating '\0'. The returned pointer
///		    remains valid until the next call to get_line() or lr_free() with
///         the same lr.
/// \details get_line() returns NULL at end of file or if there is an error with 
/// 		 memory allocation.

#define INIT_SIZE 1		/* INITIALIZED SIZE */
#define EOL '\n'		/*   END  OF  LINE  */

	/* READ LINE FROM FILE */
char *get_line(FILE *f)
{
	char *line;
	int size = 0, buf_size;
	
	#define defaut_size 9		/* Default size */
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
		
		if (line[size - 1] == EOL)
			return line;
	}
	
	return line;
}	
	
char *get_line(struct line_reader *lr, size_t *len)
{
	size_t newsiz;
	int c;
	*len = 0;		/* Start with empty line */
	for(;;)
	{
		c = fgetc(lr->f);	/* Read next character */
		
		if (c == EOF)
		{
			if (*len == 0)
				return NULL;
			else
				return lr->buf;
		}
		else
		{			/* Append (c) to the buffer */
			if (!lr->buf)	
			{
				newsiz  = INIT_SIZE;
				lr->buf = malloc(newsiz * sizeof(char));
				if (!lr->buf)
					return NULL;
				lr->siz = newsiz;
			}
			else
				if (*len == lr->siz)	
				{
					newsiz *= 2;	/* Need a bigger buffer! */
					char *tmp = realloc(lr->buf, newsiz * sizeof(char));
					if (!tmp)
						return NULL;
					lr->buf = tmp;
					lr->siz = newsiz;
				}
				
			lr->buf[(*len)++] = (char) c;		/* Save character *//* Count length */
			if (c == EOL)
				return lr->buf;
		}
	}
}

/// \author Binh Nguyen Duc
/// \brief  Frees internal memory used by lr.
	
	/* FREE STRUCT */
void lr_free(struct line_reader *lr)
{
	free(lr->buf);
	lr->buf = NULL;
	lr->siz = 0;
}
