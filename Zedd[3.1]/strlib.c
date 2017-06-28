#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

	/* STRPBRK */
/// \author Binh Nguyen Duc
/// \brief Find the first occurrence in second string of a character in first string (excluding NUL).
/// \param[in] 2 strings (type const char *)

char *_strpbrk(const char *s1, const char *s2)
{
	if (*s2 == 0)
		return NULL;	// case: string is not existed
	
	while (*s1)
	{
		const char *src = s2;
		while (*src)
		{
			if (*src == *s1)
				return (char *)(s1);	// current char of first string
			src++;
		}	
		s1++;
	}
	return NULL;
}

	/* STRLEN */
/// \author Binh Nguyen Duc
/// \brief Identify the length of string
/// \param[in] string (const)

size_t _strlen(const char *s)
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

	/* STRDUP */
/// \author Binh Nguyen Duc
/// \brief Try to allocate enough memory to hold the old string 
///        (plus a null character to mark the end of the string)
/// \details return pointer to duplicated string
/// 		 if the allocation failed, it returns NULL immediately
/// \param[in] string need duplicating

char *_strdup(const char *s)
{
	size_t n = _strlen(s);			// count length of string
	char *dup = malloc((n+1) * sizeof(char));	// allocate memory for copied string
	if (!dup)
		return NULL;	// error
	for (int i = 0; i <= n; i++)
		dup[i] = s[i];	// make copy
	return dup;
}