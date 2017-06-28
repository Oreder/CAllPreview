#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int err = 0;
	printf("\n#TEST \"lib.h\"\n");
		/* --- TEST copy_uniq() --- */
		
	char *str_0 = NULL;
	char *str_res;
	int va;
	
	va = copy_uniq(str_0, NULL, 0);
	if (va != -1)
		err++;
	
	char str_1[] = "Hello, world!", src_1[] = "Helo, wrd!";
	va = copy_uniq(str_1, NULL, 0);
	if (va != 11)
		err++;
	
	str_res = malloc(va);
	copy_uniq(str_1, str_res, va);
	if (strcmp(src_1, str_res) != 0)
		err++;
	free(str_res);
	
	
	char str_2[] = "aaaaa", src_2[] = "a";
	va = copy_uniq(str_2, NULL, 0);
	if (va != 2)
		err++;
	
	str_res = malloc(va);
	copy_uniq(str_2, str_res, va);
	if (strcmp(src_2, str_res) != 0)
		err++;
	free(str_res);
	
	
	char str_3[] = "aabbbaabcba", src_3[] = "abc";
	va = copy_uniq(str_3, NULL, 0);
	if (va != 4)
		err++;
	
	str_res = malloc(va);
	copy_uniq(str_3, str_res, va);
	if (strcmp(src_3, str_res) != 0)
		err++;
	free(str_res);
	
	
	char str_4[] = "012012010100000003", src_4[] = "0123";
	va = copy_uniq(str_4, NULL, 0);
	if (va != 5)
		err++;
	
	str_res = malloc(va);
	copy_uniq(str_4, str_res, va);
	if (strcmp(src_4, str_res) != 0)
		err++;
	free(str_res);
	
	char str_5[] = "aaaadna", src_5[] = "adn";
	va = copy_uniq(str_5, NULL, 0);
	if (va != 4)
		err++;
	
	str_res = malloc(va);
	copy_uniq(str_5, str_res, va);
	if (strcmp(src_5, str_res) != 0)
		err++;
	free(str_res);
	
	printf("\n+ COPY_UNIQ(): ");
	if (!err)
		printf("PASS\n");
	else
		printf("FAIL\n");
}