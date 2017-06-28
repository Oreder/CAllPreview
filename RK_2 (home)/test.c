#include "stack.h"

/// \author  Binh Nguyen Duc
/// \details Compare data of stack list with const array;
///			 return number of errors

int cmp(const int *a, const int size, struct stack *s)
{
	int err = 0, count = 0;
	struct stack *tmp = s;
	while (tmp)
	{
		
		if (tmp->value != a[count++])
			err++;
		tmp = tmp->prev;
		
		if (count > size)
			return 1;
	}
	return err;
}

int main()
{
	int err = 0;
	struct stack *stack_l = NULL, *stack_h = NULL;
	printf("\nTEST \"stack.h\":");
	
	int border = 0;		/* [DEC_INSERT] */
	const int a_1[] = {5, 3, 2, 2, 1};
	
	/* CASE: low - NULL; high - exist */
	fill_stack(&stack_l, &stack_h, border, 2);
	fill_stack(&stack_l, &stack_h, border, 2);
	fill_stack(&stack_l, &stack_h, border, 1);
	fill_stack(&stack_l, &stack_h, border, 5);
	fill_stack(&stack_l, &stack_h, border, 3);
	
	if (stack_l)
		err++;
	
	err += cmp(a_1, 5, stack_h);
	
	free_stack(stack_h);
	stack_h = NULL;
	
	border = 5;		/* [ASC_INSERT] */
	const int a_2[] = {-5, -2, -1, -1, 0, 2, 3};
	
	/* CASE: low - exist; high - NULL */
	fill_stack(&stack_l, &stack_h, border, -2);
	fill_stack(&stack_l, &stack_h, border, -1);
	fill_stack(&stack_l, &stack_h, border, -1);
	fill_stack(&stack_l, &stack_h, border,  2);
	fill_stack(&stack_l, &stack_h, border, -5);
	fill_stack(&stack_l, &stack_h, border,  3);
	fill_stack(&stack_l, &stack_h, border,  0);
	
	if (stack_h)
		err++;
	
	err += cmp(a_2, 7, stack_l);
	
	free_stack(stack_l);
	stack_l = NULL;
	
	/* CASE: low - exist; high - exist */
	border = 3;
	const int a_3_l[] = {1};
	const int a_3_h[] = {5, 3};
	
	fill_stack(&stack_l, &stack_h, border, 3);
	fill_stack(&stack_l, &stack_h, border, 5);
	fill_stack(&stack_l, &stack_h, border, 1);
	
	err += cmp(a_3_l, 1, stack_l);
	err += cmp(a_3_h, 2, stack_h);
	
	free_stack(stack_l); free_stack(stack_h);
	
	printf("\tTotal errors: [%d]\t", err);
	
	if (err == 0)
		printf("--- PASS!\n");
	else
		printf("--- FAIL!\n");
	
	return 0;
}