#include <stdio.h>
#include <string.h>

	/* LENGTH OF STRING */
size_t length(const char *s)	/* -- TESTED -- */
{
	size_t n;
	for (n = 0; s[n] != '\0'; n++)
		;
	return n;
}

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("1234\n\n78", fp);
   //fseek( fp, -5, SEEK_END);
   
   
   fclose(fp);
   
	
   fp = fopen("file.txt","r");
char s[10];
   fgets(s, 10, fp);
   puts(s);
   getchar();
   for (int i = 0; i < length(s); i++)
	   if (s[i] == '\n')
		printf("_");
		else
			printf("%c ", s[i]);
   
   //printf("L: %d %d", strlen(s), length(s));
   fclose(fp);
   return(0);
}