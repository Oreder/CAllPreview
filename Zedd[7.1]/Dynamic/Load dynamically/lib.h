#ifndef __LIB_H__
#define __LIB_H__

#ifdef  ARR_EXPORTS		/* MACRO IS USED TO IDENTIFY THE AIM OF .DLL */
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#include <stdio.h>

ARR_DLL int __cdecl read_size(FILE *, int *);

ARR_DLL int __cdecl read_array(FILE *, int *);

ARR_DLL int __cdecl print_array(const int *, const int *);

ARR_DLL int __cdecl execute(const int *, const int *);

#endif		// __LIB_H__