#ifndef FILTER_H
#define FILTER_H

/* counting size */
int size_out(const int *a, const int *pe);
/* get filtered array */
int get_filter(const int *a, const int *pe, int *new);

#endif