#ifndef __SNP_H__
#define __SNP_H__

#define MAX_OCT 12

char *convert(const unsigned int);

size_t _strlen(const char *);

char *_strcat(int n, char *dst, const char *src);

int part_snprintf(char *s, size_t n, const char *format, ...);

#endif