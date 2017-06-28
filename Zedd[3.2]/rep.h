#ifndef __REP__H__
#define __REP__H__

/*Set definition structure of string. All members are private. */
struct _string
{
	size_t allocated;	/* allocated size */
	size_t len;			/* length */
	char  *buf;			/* string */
};

typedef struct _string string;

void init_string(string *);

void buf_free(string *);

size_t length(const char *);

int append(string *, char );

int match(const int index, const char *src, size_t src_len, const char *arg, size_t arg_len);

char *replace(const char *src, const char *arg, const char *res);

void fsave(FILE *, const char *);

#endif