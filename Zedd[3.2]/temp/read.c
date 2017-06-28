#include <stdlib.h>	/* exit, malloc, realloc, free */
#include <stdio.h>	/* fopen, fgetc, fputs, fwrite */
 
struct line_reader 
{
	/* All members are private. */
	FILE	*f;
	char	*buf;
	size_t	 siz;
};
 
/*
 * Initializes a line reader _lr_ for the stream _f_.
 */
void lr_init(struct line_reader *lr, FILE *f)
{
	lr->f = f;
	lr->buf = NULL;
	lr->siz = 0;
}

/*
 * Reads the next line. If successful, returns a pointer to the line,
 * and sets *len to the number of characters, at least 1. The result is
 * _not_ a C string; it has no terminating '\0'. The returned pointer
 * remains valid until the next call to next_line() or lr_free() with
 * the same _lr_.
 *
 * next_line() returns NULL at end of file, or if there is an error (on
 * the stream, or with memory allocation).
 */
 
#define INIT_SIZE 1
#define EOL '\n'

char *next_line(struct line_reader *lr, size_t *len)
{
	size_t newsiz; 
	int c;
	*len = 0;			/* Start with empty line. */
	for(;;)
	{
		c = fgetc(lr->f);	/* Read next character. */
			if (ferror(lr->f))
			return NULL;
		if (c == EOF)
		{
			if (*len == 0)
				return NULL;
			else
				return lr->buf;
		}
		else
		{
				/* Append c to the buffer. */
			if (!lr->buf)
			{
				lr->buf = malloc(newsiz * sizeof(char));
				if (!lr->buf)
					return NULL;
				newsiz = INIT_SIZE;
				lr->siz = INIT_SIZE;
			}
			else
				if (*len == lr->siz)		/* Append c to the buffer. */
				{
					newsiz *= 2;		/* Need a bigger buffer! */
					char *tmp = realloc(lr->buf, newsiz * sizeof(char));
					if (!tmp)
						return NULL;
					lr->buf = tmp;
					lr->siz = newsiz;
				}
				
			lr->buf[(*len)++] = c;
			if (c == EOL)
				return lr->buf;
		}
	}
}


/*
 * Frees internal memory used by _lr_.
 */
void lr_free(struct line_reader *lr)
{
	free(lr->buf);
	lr->buf = NULL;
	lr->siz = 0;
}

void print(const char *src, size_t len)
{
	printf("LINE: ");
	for (size_t i = 0; i < len; i++)
		printf("%c", src[i]);
	printf("\n");
}



/*
 * Read a file line by line.
 * Recoded by Binh Nguyen Duc.
 */ 
int main()
{
	struct line_reader lr;
	FILE *f = fopen("a.txt", "r");
	if (!f)
		printf("Error #1\n");
	
	size_t len;
	char *line;
	
	lr_init(&lr, f);
	while (!feof(f))
	{
		line = next_line(&lr, &len);
		print(line, len);
		lr_free(&lr);
	}
	fclose(f);
	
	return 0;
}
