#include "stack.h"

	/* MAIN */
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error #1: Command has not enough parameters! Exit program..\n");
		return -1;
	}
	
	int border, i;
	printf("Input border-number: ");
	scanf("%d", &border);	// scan border-number
	
	FILE *f = fopen(argv[1], "r");
	if (!f)
	{
		printf("Error #2: File does not exist! Exit program..\n");
		return -2;
	}
	
	struct stack *stack_l = NULL, *stack_h = NULL;		// Initialize stack lists
	while (fscanf(f, "%d", &i) == 1)
	{
		fill_stack(&stack_l, &stack_h, border, i);
		print_stack(stack_l, stack_h);
	}
	fclose(f);
	
	if (stack_l == NULL && stack_h == NULL)
		printf("Error #4: File is empty or contains something wrong!\n");	// NULL stack
	else
	{
		free_stack(stack_l); free_stack(stack_h);
	}

	return 0;
}