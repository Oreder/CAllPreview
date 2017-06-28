#ifndef __LIB_H__
#define __LIB_H__

#include <stdio.h>

int read_size(FILE *, int *);

int read_array(FILE *, int *);

int print_array(const int *, const int *);

int execute(const int *, const int *);

#endif		// __LIB_H__