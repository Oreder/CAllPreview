#ifndef __LIB__H__
#define __LIB__H__

#include <stdio.h>
#include <stdlib.h>

struct line_reader
{
	FILE	*f;
	char	*buf;
	size_t	 siz;
};

void lr_init(struct line_reader *, FILE *);

#define INIT_SIZE 1

#define EOL '\n'

char *get_line(struct line_reader *, size_t *);

void lr_free(struct line_reader *);

#endif
