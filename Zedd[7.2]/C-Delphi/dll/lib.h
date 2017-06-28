#ifndef __LIB_H__
#define __LIB_H__

#ifdef  EXPORTS
#define CD_DLL __declspec(dllexport)
#else
#define CD_DLL __declspec(dllimport)
#endif

CD_DLL void __cdecl fill_array(int *arr, const int size);

CD_DLL int  __cdecl copy_uniq(char *str, char *str_res, int res_len);

#endif