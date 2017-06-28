#ifndef READ_H
#define READ_H

int read_size(FILE *f, int *ncol, int *nrow);

int read_matrix(FILE *f, int *p);

int print_matrix(const int *p, const int size, const int ncol);

#endif