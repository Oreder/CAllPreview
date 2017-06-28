#include "stack.h"

/// \author  Binh Nguyen Duc
/// \details Create new node-stack

struct stack *new(const int value)
{
	struct stack *new_node = malloc(sizeof(struct stack));
	if (new_node)
	{
		new_node->value = value;
		new_node->prev  = NULL;
	}
	return new_node;
}

/// \author  Binh Nguyen Duc
/// \details Insert new node into stack list by ASCENDING

void asc_insert(struct stack **stack_low, struct stack *new_node)
{
	if (*stack_low == NULL || (*stack_low)->value >= new_node->value)
	{
		new_node->prev = *stack_low;		// case top stack or NULL
		*stack_low = new_node;
	}
	else
	{
		struct stack *cur = *stack_low;
		while (cur->prev != NULL && cur->prev->value < new_node->value)
			cur = cur->prev;				// search for suitable place
		
		new_node->prev = cur->prev;
		cur->prev = new_node;
	}
}

/// \author  Binh Nguyen Duc
/// \details Insert new node into stack list by DECENDING

void dec_insert(struct stack **stack_high, struct stack *new_node)
{
	if (*stack_high == NULL || (*stack_high)->value <= new_node->value)
	{
		new_node->prev = *stack_high;		// case top stack or NULL
		*stack_high = new_node;
	}
	else
	{
		struct stack *cur = *stack_high;
		while (cur->prev != NULL && cur->prev->value > new_node->value)
			cur = cur->prev;				// search for suitable place
		
		new_node->prev = cur->prev;
		cur->prev = new_node;
	}
}

/// \author  Binh Nguyen Duc
/// \details Print stack list

void print_stack(const struct stack *stack_low, const struct stack *stack_high)
{
	const struct stack *source;

	printf("\n# Stack_L(");
	source = stack_low;
	while (source)
	{
		printf("%3d", source->value);
		source = source->prev;
	}
	
	printf(")\n  Stack_H(");
	source = stack_high;
	while (source)
	{
		printf("%3d", source->value);
		source = source->prev;
	}
	printf(")\n");
}

/// \author  Binh Nguyen Duc
/// \details Free stack list

void free_stack(struct stack *source)
{
	struct stack *tmp = source;
	while (tmp)
	{
		tmp = source->prev;
		free(source);
		source = tmp;
	}
}

/// \author  Binh Nguyen Duc
/// \details Fill stack lists by default with border-number

void fill_stack(struct stack **stack_l, struct stack **stack_h, const int border, const int value)
{
	struct stack *new_node = new(value);
	if (!new_node)
	{
		printf("Error #3: Memory allocation!\n");
		return ;
	}
	
	if (value < border)
		asc_insert(stack_l, new_node);
	else
		dec_insert(stack_h, new_node);
}
