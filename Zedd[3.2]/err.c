#include <stdio.h>
#include "err.h"

/// \author Binh Nguyen Duc
/// \details Give message of errors
/// \param[in] case error

	/* MESSAGES */
void message(const int i)
{
	switch (i)
	{
		case 1: 
			printf("Error #1: Command is not executed. Exiting..\n");
			break;
		case 2:
			printf("Error #2: [I/O] File does not exist or can not open file..\n");
			break;
		case 3:
			printf("Error #3: Memory has not enough to allocate! Exiting..\n");
			break;
		
		default:
			getchar();
	}
}