#ifndef READ_H
#define READ_H

/* reading number elements of array */
int read_size(FILE *f, int *size);

/* procedure reads array from file */
int read_array(FILE *f, int *a);

/* procedure prints out array */
int print_array(const int *a, const int *pe);

/* procedure prints array to file */
int fprint_array(FILE *f, const int *a, const int *pe);

#endif