#include <stdio.h>
#include <assert.h>
#include "search.h"

/// \author Binh Nguyen Duc
/// \brief module finds MIN value of a[0]*a[1], a[1]*a[2],..., a[N-2]*a[N-1]
///  where a - const array. Use library "search.h"
/// \param[in] a - array, pe - pointer to right border
/// \param[out] minimum value

int execute(const int *a, const int *pe)	// main
{
	assert(pe - a >= 2); // check number elements
	int best, cur;
	const int *p;
	p = pe-1;
	best  = *p;
	best *= *(p-1);
	
	for(p = pe - 1; p > a; p--)
	{
		cur = *p; cur *= *(p-1);
		best = (best < cur)? best : cur;	// count min
	}
	return best;
}