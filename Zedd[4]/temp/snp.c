#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "snp.h"

/// \author Binh Nguyen Duc
/// \brief  Identify the length of string
/// \param[in] string (const)

	/* LENGTH OF STRING */
size_t length(const char *s)	/* -- TESTED -- */
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

/// \author Binh Nguyen Duc
/// \brief  Identify size (memory) should be allocated (apply for octal system)
/// \param[in] integer number

	/* SIZE of ALLOCATION */
int size(const int z, const int base)
{
	int i, n = z;
	for (i = 1; n/base >= 1; i++)
		n /= base;
	return i;
}

/// \author Binh Nguyen Duc
/// \brief  Convert decimal number to octal (type string)
/// \param[in] decimal number

	/* OCTAL CONVERT */
char *convert(const int z)
{
	#define BASE 8			/* OCTAL SYSTEM */
	#define MAX_SIZE 11		/* MAX SIZE OF CONVERTED NUMBER IN OS */
	#define ABS(z) (((z) < 0) ? (-z) : (z))		/* ABSOLUTE VALUE */
	int n = size(ABS(z), BASE);	// Find size of memories should to be allocated
	
	if (z < 0)
		n = MAX_SIZE;		// CASE: negative number
	
	char *res = malloc((n + 1) * sizeof(char));
	if (!res)
		return NULL;		// CASE: Error of allocations
	
	for (int i = 0; i < n; i++)
		res[i] = '0';		// CASE: positive number
	if (z < 0)
		res[0] = '2';		// CASE: negative number
	res[n--] = '\0';		/* FINISH: Format string */
	
	if (z != 0)
	{
		#define INT_MIN -2147483648
		int p = z;
		if (z < 0)			// Set up number
			p = z - INT_MIN;
	
		while (p != 0)
		{
			res[n--] += (p % BASE);		// MAIN
			p /= BASE;
		}
	}
	
	return res;
}

/// \author  Binh Nguyen Duc
/// \brief   Append string, which was allocated
/// \param[in] allocated string, limited size, char need to append

	/* APPEND BY CHAR */
void append(char *s, size_t n, const char c)
{
	int i = length(s);
	if (i < n - 1)
	{
		s[i] = c;			// add up character
		s[i+1] = '\0';		// end string
	}
}

/// \author  Binh Nguyen Duc
/// \brief   Append string, which was allocated
/// \param[in] allocated string, limited size, char need to append
	
	/* SNPRINTF */
int part_snprintf(char *s, size_t n, const char *format, ...)
{
	s[0] = '\0';		// Set beginning string
	
	if (n < 1)			// CASE: error number limited string output
		return -1;
	
	va_list va;
	va_start(va, format);
	
	size_t NF = length(format);
	
	if (NF == 0)		// CASE: empty string-in
		return 0;
	
	for (size_t i = 0; i < NF; i++)
	{
		if ((format[i] == '%') && (i+1 < NF)) 		// CASE of signals
		{
			switch(format[i+1])
			{
				case 's':		/* SIGNAL: %s */
					{
						const char *p = va_arg(va, const char *);
						size_t p_len = length(p);
						for (size_t j = 0; j < p_len; j++)
						{
							append(s, n, p[j]);		// save string
							if (i + j + 1 == n - 1)
								return 0;			// CASE: LENGTH = LIMITED
						}
					}
					break;
					
				case 'o':		/* SIGNAL %o */
					{
						int num = va_arg(va, int);
						
						char *oct = convert(num);
						if (!oct)			// CASE: Error of allocation
							return -3;
						
						size_t oct_len = length(oct);
						for (size_t j = 0; j < oct_len; j++)
						{
							append(s, n, oct[j]);	// save string
							if (i + j == n - 1)
							{
								free(oct);	// CASE: LENGTH = LIMITED
								return 0;
							}
						}
						free(oct);
					}
					break;
						
				case 'c':		/* SIGNAL %c */
					{
						char c = va_arg(va, int);
						append(s, n, c);	// save string
					}
					break;
					
				default:
					;
			}
			i++;
		}
		else
			append(s, n, format[i]);	// save string
	}
	
	va_end(va);
	return 0;
}
