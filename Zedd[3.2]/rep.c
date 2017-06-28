#include <stdio.h>
#include <stdlib.h>
#include "rep.h"

/// \author Binh Nguyen Duc
/// \brief  Initialize string.

	/* INITIALIZE */
void init_string(string *p)
{
	p->allocated = 0;
	p->len = 0;
	p->buf = NULL;
}

/// \author Binh Nguyen Duc
/// \brief  Frees internal memory used by buf.

	/* FREE STRUCT */
void buf_free(string *p)
{
	free(p->buf);
	p->buf = NULL;
	p->allocated = 0;
	p->len = 0;
}

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
int append(string *p, char c)
{
	if (!p->buf)		// case: buffer was not allocated
    {
		#define INIT_SIZE 1
		p->buf = malloc(INIT_SIZE * sizeof(char));

        if (!p->buf)
            return -1;

        p->allocated = INIT_SIZE;
    }
    else				// case: expand allocated size
        if (p->len == p->allocated)
        {
			p->allocated *= 2;
			
			char *tmp = realloc(p->buf, p->allocated * sizeof(char));
			
			if (!tmp)
				return -1;
			
			p->buf = tmp;
        }

	p->buf[p->len] = (char) c;	// add up character
	p->len++;					// change length

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
/// \param[in] source string, match string and replace string

	/* FIND and REPLACE ALL */
char *replace(const char *src, const char *arg, const char *res)
{
	size_t src_len = length(src);		// src's length (string source)
	size_t arg_len = length(arg);		// arg's length (string to match)
	size_t res_len = length(res);		// res's length (string to replace)
	
	string p;			// working string
	init_string(&p);	// initialize string p
	
	for(int i = 0; i < src_len; i++)
	{
		if (match(i, src, src_len, arg, arg_len))
		{
			i += arg_len - 1;
			for (int j = 0; j < res_len; j++)
				append(&p, res[j]);
		}
		else
			append(&p, src[i]);
	}
	
	if (p.len == 0)		// CASE: result = NULL
		return NULL;
	
	char *tmp = malloc((p.len + 1) * sizeof(char));	// CASE: result exists
	if (!tmp)
		return NULL;
	
	for (int i = 0; i < p.len; i++)		// SAVE as new string
		tmp[i] = p.buf[i];
	tmp[p.len] = '\0';
	
	buf_free(&p);		// free working string (struct type)
	
	return tmp;
}

/// \author Binh Nguyen Duc
/// \brief  Save string to available file
/// \param[in] file and string (struct type)

	/* SAVE TO FILE */
void fsave(FILE *f, const char *p)
{
	size_t n = length(p);
	for (int i = 0; i < n; i++)
		fprintf(f, "%c", p[i]);
}
