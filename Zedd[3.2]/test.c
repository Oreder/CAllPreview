	/* ----- TEST ----- */
/// \author  Binh Nguyen Duc
/// \brief   String (C) implemetation
/// \details Test function REPLACE string in the library "rep.h"
/// 		 and function READ LINE from file in the library "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rep.h"
#include "lib.h"

int main()
{
	int err;	// errors counting
	
		/* ----- TEST "LIB.H" ----- */
	
	printf("\n_____TESTING \"LIB.H\": ");
	err = 0;
	
	FILE *f = fopen("bin.txt", "r");
	if (!f)
		return 0;
	
	char *line;
	
	const char first_line[] = "1#1ask   kDHMggg77676rf   q  2q ieuZ8$^ ()aLp;\n";
	line = get_line(f);
	if (strcmp(line, first_line) != 0)
		err++;
	free(line);

	const char second_line[] = "\n";
	line = get_line(f);
	if (strcmp(line, second_line) != 0)
		err++;
	free(line);
	
	const char third_line[] = "?  55.1913%   <> 2,5001 __[!]\n";
	line = get_line(f);
	if (strcmp(line, third_line) != 0)
		err++;
	free(line);
	
	fclose(f);
	
	if (!err)
		printf("_____RESULT: PASSED!\n");
	else
		printf("_____RESULT: FAILED!\n");
	
		/* ----- TEST "REP.H" ----- */
	
	printf("\n_____TESTING \"REP.H\":\n");

		/* ----- TEST "APPEND" ----- */
	printf("+ Function \"APPEND\" : ");
	err = 0;
	string p;
	init_string(&p);
	const char src[] = "Hello, world! \n";
	for (int i = 0; src[i] != '\0'; i++)
	{
		append(&p, src[i]);
		if ((p.len != i+1) || p.buf[p.len -1] != src[i])
			err++;
	}
	buf_free(&p);
	if (!err)
		printf("PASSED!\n");
	else
		printf("FAILED!\n");
	
		/* ----- TEST "MATCH" ----- */
	printf("+ Function  \"MATCH\" : ");
	err = 0;
	
	const char m_1[] = "Hello";				// normal string
	const char m_2[] = "o";					// short  string
	const char m_3[] = "Hello, world";		// long	  string
	const char m_4[] = "worlD";				// not matched
	const char m_5[] = "setaspectratio";	// not matched
	const char m_6[] = "";					// NULL
	
	if (!match(0, src, strlen(src), m_1, strlen(m_1)))
		err++;
	
	if (!match(4, src, strlen(src), m_2, strlen(m_2)))
		err++;
	
	if (!match(8, src, strlen(src), m_2, strlen(m_2)))
		err++;

	if (!match(0, src, strlen(src), m_3, strlen(m_3)))
		err++;
	
	if (match(3, src, strlen(src), m_1, strlen(m_1)))
		err++;
	
	if (match(strlen(src)-2, src, strlen(src), m_2, strlen(m_2)))
		err++;
	
	if (match(7, src, strlen(src), m_3, strlen(m_3)))
		err++;
	
	if (match(strlen(src), src, strlen(src), m_1, strlen(m_1)))
		err++;
	
	if (match(0, src, strlen(src), m_4, strlen(m_4)))
		err++;
	
	if (match(2, src, strlen(src), m_5, strlen(m_5)))
		err++;
	
	if (match(0, src, strlen(src), m_6, strlen(m_6)))
		err++;
	
	if (!err)
		printf("PASSED!\n");
	else
		printf("FAILED!\n");
	
		/* ----- TEST "REPLACE" ----- */
	printf("+ Function \"REPLACE\": ");
	err = 0;
	char *rep;
	const char src_1[] = "aaaaB";		/* MEDIUM string */
	
	const char rep_1[] = "BBBBB";		/* same length */
	rep = replace(src_1, "a", "B");
	if (strcmp(rep, rep_1) != 0)
		err++;
	free(rep);
	
	const char rep_2[] = "B";			/* replace with empty string */
	rep = replace(src_1, "aa", "");
	if (strcmp(rep, rep_2) != 0)
		err++;
	free(rep);
	
	const char rep_3[] = "aB";			/* 3 letters */
	rep = replace(src_1, "aaa", "");
	if (strcmp(rep, rep_3) != 0)
		err++;
	free(rep);
	
	const char rep_4[] = "aaaB";		/* 2 last letters */
	rep = replace(src_1, "aB", "B");
	if (strcmp(rep, rep_4) != 0)
		err++;
	free(rep);
	
	const char rep_5[] = "123 123 123 123 B";	/* replace with bigger string */
	rep = replace(src_1, "a", "123 ");
	if (strcmp(rep, rep_5) != 0)
		err++;
	free(rep);
	
	const char rep_6[] = "TEST";		/* replace with smaller string */
	rep = replace(src_1, "aaaaB", "TEST");
	if (strcmp(rep, rep_6) != 0)
		err++;
	free(rep);
	
	const char rep_0[] = "aaaaB";		/* string not match (smaller) */
	rep = replace(src_1, "A", "()");
	if (strcmp(rep, rep_0) != 0)
		err++;
	free(rep);
	
	rep = replace(src_1, "aaaaa", "()");	/* string not match (bigger) */
	if (strcmp(rep, rep_0) != 0)
		err++;
	free(rep);
	
	
	const char src_2[] = "  01201   010010 0110";	/* LONG string */
	
	const char rep_7[] = "  _12_1   _1__1_ _11_";	/* replace with same length */
	rep = replace(src_2, "0", "_");
	if (strcmp(rep, rep_7) != 0)
		err++;
	free(rep);
	
	const char rep_8[] = "  #2#   #0#0 #10";		/* replace with smaller string */
	rep = replace(src_2, "01", "#");
	if (strcmp(rep, rep_8) != 0)
		err++;
	free(rep);
	
	const char rep_9[] = "  01two01   010010 0110";	/* replace with bigger string */
	rep = replace(src_2, "2", "two");
	if (strcmp(rep, rep_9) != 0)
		err++;
	free(rep);
	
	const char rep_10[] = "012010100100110";		/* delete all spaces */
	rep = replace(src_2, " ", "");
	if (strcmp(rep, rep_10) != 0)
		err++;
	free(rep);
	
	
	const char src_0[] = "aa";			/* SHORT string */
	
	//const char rep_11[] = "";
	rep = replace(src_0, "a", "");
	if (rep != NULL)							/* string after replace is empty */
		err++;
	
	const char rep_12[] = "bbbbbb";
	rep = replace(src_0, "a", "bbb");	/* replace with bigger string */
	if (strcmp(rep, rep_12) != 0)
		err++;
	free(rep);
	
	const char rep_13[] = "IU7";
	rep = replace(src_0, "aa", "IU7");	/* replace full string with another */
	if (strcmp(rep, rep_13) != 0)
		err++;
	free(rep);
	
	rep = replace(src_0, "aaa", "");	/* string not match */
	if (strcmp(rep, src_0) != 0)
		err++;
	free(rep);
	
	if (!err)
		printf("PASSED!\n");
	else
		printf("FAILED!\n");
	
	return 0;
}
