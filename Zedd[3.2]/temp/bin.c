#include <stdio.h>
#include <stdlib.h>

	/* STRLEN */
/// \author Binh Nguyen Duc
/// \brief Identify the length of string
/// \param[in] string (const)

size_t length(const char *s)
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}


/// \author Binh Nguyen Duc
/// \brief  Print line (string)
/// \param[in] string and it's length

	/* PRINT LINE *//*
void print(const char *src, size_t len)
{
	//printf("LINE: ");
	for (size_t i = 0; i < len; i++)
		printf("%c", src[i]);
	printf("\n");
}*/


int main(int argc, char **argv)
{
	char arg[100];
	printf("Input: "); gets(arg);
	
	printf("\nL: %d", length(argv[1]));
	return 0;
}