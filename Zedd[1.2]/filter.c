/* ----- FILTER module ----- */

#include <stdio.h>
#include <assert.h>
#include "filter.h"

/// \author Binh Nguyen Duc
/// \brief function counts number satisfied element after filtering
/// \details return size of new array need to allocate
/// \param[in] array and pointer to it's out border

/* counting size */
int size_out(const int *a, const int *pe)
{
	assert(pe - a > 1);
	const int *p;
	int count = 0;
	int sum = *--pe;	// sum is set to last element
	for (p = pe - 1; p >= a ; p--)
	{
		if (*p > sum)
			count++;
		sum += *p;		// sum up
	}
	return count;
}


/// \author Binh Nguyen Duc
/// \brief procedure gets new filtered array
/// \param[in] array and pointer to it's out border
/// \param[out] new array

/* get filtered array */
int get_filter(const int *a, const int *pe, int *new)
{
	printf("Filter result: ");
	const int *p;
	int sum = *--pe;	// set first value of sum
	for (p = pe - 1; p >= a ; p--)
	{
		if (*p > sum)
		{
			printf("%d ", *p);	// print to screen
			*new = *p;	// save satisfied elements
			new++;
		}
		sum += *p;
	}
	printf("\n\n");
	return 0;
}