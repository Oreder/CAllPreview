#include <stdio.h>
#include <stdlib.h>

/// \author Binh Nguyen Duc
/// \brief  Identify the length of string
/// \param[in] string (const)

	/* LENGTH OF STRING */
size_t length(const char *s)	/* -- TESTED -- */
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

/// \author  Binh Nguyen Duc
/// \brief   Append string, using structure to reallocate memory
/// \details return -1 if there are errors of allocation, else 0.
/// \param[in] structure string and character need appending

	/* APPEND BY CHAR */
int append(char *p, const char c)
{
	size_t len;
	if (p == NULL)		// case: string is not allocated
    {
		#define INIT_SIZE 1
		p = malloc((INIT_SIZE + 1) * sizeof(char));
		
		if (!p)
            return -1;
		
		len = INIT_SIZE;
    }
    else				// case: expand allocated size
    {
		len = length(p);
		char *tmp = realloc(p, (len + 1) * sizeof(char));
		
		if (!tmp)
			return -1;
		
		p = tmp;
	}
	printf("|%d| ", len);
	p[len-1] = c;		// add up character
	puts(p); getchar();
    return 0;
}

/// \author  Binh Nguyen Duc
/// \brief   Check string match to substrings of source or not
/// \details return 1 in case of matching, else 0
/// \param[in] index need checking, source string, substring and its' length

	/* MATCH STRING */
int match(const int index, const char *src, size_t src_len, const char *arg, size_t arg_len)
{
	if ((src[index] == arg[0]) && (index + arg_len <= src_len))
	{
		int j = 1;
		while (j < arg_len)
			if (src[index + j] == arg[j])
				j++;
			else
				break;
		if (j == arg_len)
			return 1;
	}
	return 0;
}

/// \author Binh Nguyen Duc
/// \brief  Replace all matched substrings from source into new string
/// \param[in] string (struct type), source and it's length, string to match and replace

	/* FIND and REPLACE ALL */
char *replace(const char *src, const char *arg, const char *res)
{
	char *p = NULL;
	size_t src_len = length(src);
	size_t arg_len = length(arg);		// arg's length (string to match)
	size_t res_len = length(res);		// res's length (string to replace)
	
	for(int i = 0; i < src_len; i++)
	{
		if (match(i, src, src_len, arg, arg_len))
		{
			i += arg_len - 1;
			for (int j = 0; j < res_len; j++)
				append(p, res[j]);
		}
		else
			append(p, src[i]);
	}
	
	return p;
}

/// \author Binh Nguyen Duc
/// \brief  Save string to available file
/// \param[in] file and string (struct type)

	/* SAVE TO FILE */
void fsave(FILE *f, const char *p)
{
	size_t n = length(p);
	for (size_t i = 0; i < n; i++)
		fprintf(f, "%c", p[i]);
}

	/* READ LINE FROM FILE */
char *get_line(FILE *f, size_t *len)
{
	char *line;
	int size = 0, buf_size;
	
	#define EOL '\n'			/* END OF LINE  */
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
		
		*len = size;
		if (line[size - 1] == EOL)
			return line;
	}
	
	return line;
}	

	/* MESSAGES */
void message(const int i)
{
	switch (i)
	{
		case 1: 
			printf("Error #1: Command is not executed. Exiting..\n");
			break;
		case 2:
			printf("Error #2: [I/O] File does not exist or can not open file..\n");
			break;
		
		default:
			getchar();
	}
}

#define ERROR_1 1	/*  COMMAND ERRORS  */
#define ERROR_2 2	/*    I/O ERRORS    */

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
		
		char *line, *p;				// line as source string
		size_t len;				// length of current line
		
		while (!feof(f))
		{
			line = get_line(f, &len);	// read line
			printf("Line: "); puts(line); getchar();
			if (!line || (len == 1))
				fprintf(g, "\n");
			else
			{
				p = replace(line, find, rep);	// replace string
				
				if (!p)
				{
					free(line);		// free working line
					fclose(f); fclose(g);
					return -3;
				}	
				printf("P: ") ; puts(p); getchar();	
				fsave(g, p);		// save working string to file
				
				free(p);		// free working string
			}
			
			free(line);		// free working line
		}
		
		fclose(f); fclose(g);
	}
	
	return 0;
}