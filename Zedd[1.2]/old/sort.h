#ifndef SORT_H
#define SORT_H

/* function exchange elements */
void swap(char *i, char *j, int n);

/* function comparisons */
int int_comp(const void *p, const void *q);
int ch_comp(const void *p, const void *q);
int db_comp(const void *p, const void *q);

/* SORT algorithm (Bubble) */
void osort(void *base, size_t nmemb, size_t size, int (*comp)(const void *, const void *));

/* [UPGRADE] SORT algorithm (Bubble) */
void bsort(void *base, size_t nmemb, size_t size, int (*comp)(const void *, const void *));

#endif