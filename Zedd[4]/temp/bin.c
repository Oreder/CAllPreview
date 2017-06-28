/* snprintf example */
#include <stdio.h>

int main ()
{
  char s[5];
  int cx;
  printf("Size: %d\n\n", sizeof(s));
  cx = snprintf (s, 15, "");
  
  printf("Va: %d\n\n", cx);
  puts(s);
  return 0;
}