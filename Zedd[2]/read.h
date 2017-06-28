#ifndef READ_H
#define READ_H

double** read_matrix(FILE *, int *, int *);

void print_to_screen(double**, const int, const int);

void print_to_file(FILE *, double**, const int, const int);

void message(const int);

#endif