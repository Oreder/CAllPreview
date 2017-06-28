#include <stdio.h>
#include <stdlib.h>


	/* LENGTH OF STRING */
size_t length(const char *s)	/* -- TESTED -- */
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

#define EOL '\n'

char *get_line(FILE *f, size_t *len)
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
		
		*len = size;
		if (line[size - 1] == EOL)
			return line;
	}
	
	return line;
}


int main()
{
	FILE *f = fopen("bin.txt", "r"); 
	size_t n;
	char *p = get_line(f, &n);
	if (!p)
		return 0; 
	printf("--------\n[%d] ", n); puts(p); free(p);
	p = get_line(f, &n); printf("--------\n[%d] ", n); puts(p); free(p);
	p = get_line(f, &n); printf("--------\n[%d] ", n); puts(p); free(p);
	
	return 0;
}