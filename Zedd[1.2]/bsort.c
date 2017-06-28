/* ----- SORT module ----- */

#include <stdio.h>
#include "bsort.h"

/// \author Binh Nguyen Duc
/// \brief function exchanges 2 elements
/// \details algorithm using type char to exchange their position

/* function exchange elements */
void swap(char *i, char *j, int n)
{
	do {
		char c = *i;
		*i++ = *j;
		*j++ = c;
	} while (--n > 0);
}

/// \author Binh Nguyen Duc
/// \brief function compares 2 elements
/// \details function is applied for type "integer"
/// \param[in] elements p, q
/// \param[out] case of value: negative, zero or positive

// Integer comparison
int int_comp(const void *p, const void *q) 
{
    const int *a = p;	// casting pointer types 
    const int *b = q;
	return *a - *b;
}


/// \author Binh Nguyen Duc
/// \brief function compares 2 elements
/// \details function is applied for type "char"
/// \param[in] elements p, q
/// \param[out] case of value: negative, zero or positive

// Char comparison
int ch_comp(const void *p, const void *q) 
{
    const char *a = p;	// casting pointer types 
    const char *b = q;
	return *a > *b;
}


/// \author Binh Nguyen Duc
/// \brief function compares 2 elements
/// \details function is applied for type "double"
/// \param[in] elements p, q
/// \param[out] case of value: negative, zero or positive

// Double comparison
int db_comp(const void *p, const void *q) 
{
	const double *a = p;	// casting pointer types 
    const double *b = q;
	return (*a > *b);
}


/// \author Binh Nguyen Duc
/// \brief procedure is used to sort array
/// \details Algorithm is applied for all type of array (void)
/// \param[in] base - array, nmemb - number elements of array, 
///	size - size of element's type, comp - function comparing
/// \param[out] sorted array

/* SORT algorithm (Bubble) */
void bsort(void *base, size_t nmemb, size_t size, int (*comp)(const void *, const void *))
{
	char *p = (char *)base;
	char *q;
	int key = nmemb-1;
	while (key > 0)
	{
		int last = 0;	// key point
		for (q = p; q < p + size * key; q += size)
			if (comp(q, q+size) > 0)
			{	
				last = (q - p)/size;
				swap(q+size, q, size);
			}
		key = last;		// set key point to last change
	}
}