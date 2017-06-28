#include "lib.h"

/// \author  Binh Nguyen Duc
/// \details Fill array of n elements by Fibonaci numbers
/// \param[in] array and size

CD_DLL void __cdecl fill_array(int *a, const int size)
{
	//if (size < 1)
		//return ;
	a[0] = 1;
	if (size == 1)
		return ;

	a[1] = 1;
	if (size == 2)
		return ;

	for (int i = 2; i < size; i++)
		a[i] = a[i-1] + a[i-2];
}

/// \author  Binh Nguyen Duc
/// \brief   COPY string UNIQUE (copy only fisrt-appeared characters from source-string)
/// \param[in] str (source), str_res (string-result) and res_len (length of str_res was allocated)
/// \details return REAL number characters, which were copied
///			 exception return -1 if NO source-string. Return 0 if size satisfied!

CD_DLL int __cdecl copy_uniq(char *str, char *str_res, int res_len)
{
	if (!str)
		return -1;				// case NULL source
	
	int tab[256] = {0};			// table ASCII characters
	int i = 0, c, k = 1;
	while ((c = str[i]) && (c != 0))
	{	
		if (!tab[c])
		{
			tab[c] = 1;
			k++;
		}	
		i++;
	}
	
	if (k > res_len)
		return k;				// return length of allocation
	
	for (i = 0, k = 0; (c = str[i]) && (c != 0); i++)
	{
		if (tab[c])
		{
			str_res[k++] = str[i];
			tab[c] = 0;			// save string
		}
	}
	
	str_res[k] = '\0';
	
	return 0;
}
