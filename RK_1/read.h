#ifndef READ_H
#define READ_H

int read_size(FILE *f, int *ncol, int *nrow);

int read_matrix(FILE *f, int *p, const int size);

int print_matrix(int *p, int ncol, int nrow);

#endif