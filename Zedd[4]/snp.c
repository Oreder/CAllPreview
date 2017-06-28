#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "snp.h"

/// \author Binh Nguyen Duc
/// \brief  Convert decimal number to octal (type string)
/// \param[in] decimal number (positive), except 0.
	
	/* OCTAL CONVERT */
char *convert(unsigned int number)
{
	#define BASE 8		// OCTAL SYSTEM 
	size_t len = 0;		// n of buffer should be allocated.
	long long int val = 0, i = 1;
	
	if (number == 0)
		len = 1;
	else
	{
		while (number != 0)
		{
			val += i * (number % BASE);		// result
			number /= BASE;
			i *= 10;
			len++;
		}
	}
	
	char *tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
	{
		printf("Error: Memory out..");
		return NULL;
	}
	
	tmp[len--] = '\0';
	for (i = len; i >= 0; i--)
	{
		tmp[i] = (val % 10) + '0';
		val /= 10;
	}
	return tmp;
}


/// \author Binh Nguyen Duc
/// \brief Identify the length of string
/// \param[in] string (const)

	/* STRLEN */
size_t _strlen(const char *s)
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

/// \author  Binh Nguyen Duc
/// \brief   (strcat) as standard function
/// \details n - limited length

char *_strcat(int n, char *dst, const char *src)
{
	char *copy = dst;
 
	while (*copy)
		(copy)++;	/* search for end of dst */
	
	while((*copy++ = *src++) && (n-- > 1))
		;		/* Copy src to end of dst */
    
	return (dst);
}

/// \author  Binh Nguyen Duc
/// \brief   Append string, which was allocated
/// \param[in] allocated string, limited size, char need to append
	
	/* SNPRINTF */
int part_snprintf(char *buf, size_t n, const char *format, ...)
{
	// assert(n < 1);
	va_list va;
	va_start(va, format);
	
	assert(format != NULL);
	
	size_t i = 0, k = 0;
	
	while (format[i] != '\0')
	{
		buf[k] = '\0';
		if (format[i] == '%') 		// CASE of signals
		{
			switch(format[i+1])
			{
				case 's':		/* SIGNAL: %s */
					{
						const char *arg = va_arg(va, char *);
						if (k < n-1)
							_strcat(n-1 - _strlen(buf), buf, arg);
						k += _strlen(arg);
					}
					break;
					
				case 'o':		/* SIGNAL %o */
					{
						unsigned int number = va_arg(va, unsigned int);
						char *arg = convert(number);
						
						if (!arg)
							return -1;
						
						if (k < n-1)
							_strcat(n-1 - _strlen(buf), buf, arg);
						
						k += _strlen(arg);
						free(arg);
					}
					break;
						
				case 'c':		/* SIGNAL %c */
					{
						char c = va_arg(va, int);
						if (k < n-1)
							buf[k++] = c;
					}
					break;
				
				default:
					printf("Error: Error of signals format!");
					return -1;	/* CASE: Lack of signals */
			}
			
			i += 2;
		}
		else
			buf[k++] = format[i++];		// save other char

	}
	
	buf[n-1] = '\0';
	va_end(va);
	
	return k;
}
