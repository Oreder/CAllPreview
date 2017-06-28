#include <stdio.h>

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

/*
char *_strpbrk(const char *s1, const char *s2)
{
	if ((*s2 == 0) || (*s1 == 0))
		return NULL;	// case: string is not existed
	
	const char *c1;		// current char of first string
	while ((c1 = s1++) && (*c1 != '\0'))		// while (*s1){... s1++;}
	{
		const char *src = s2, *c2;
		while ((c2 = src++) && (*c2 != '\0'))
			if (*c2 == *c1)
				return (char *)(c1);
	}
	return NULL;
}
*/

int main()
{
	const char *s1 = "system is protected";
	const char *s2 = "restorecrtmode";
	
	char *c = _strpbrk(s1, s2);
	printf("[1. strpbrk] Result: ");
	if (c == NULL)
		printf("No char is found!\n");
	else
		if (*c == ' ')
			printf("(space)\n");
		else
			printf("%c\n", *c);
	return 0;
}