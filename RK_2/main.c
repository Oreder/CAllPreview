#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void push(struct stack **source, const int value)
{
	struct stack *tmp = malloc(sizeof(struct stack));
	if (!tmp)
		return ;

	tmp->value = value;
	tmp->prev = *source;

	*source = tmp;
}


int is_empty(struct stack *s)
{
	if (s == NULL)
		return 1;
	else
		return 0;
}


int pop(struct stack **source)
{
	if (is_empty(*source))
	{
		printf("Stack is empty!\n");
		return 0;
	}

	struct stack *last = (*source)->prev;
	
	int rm_val = (*source)->value;
	
	free(*source);

	*source = last;
	
	return rm_val;
}


void read_data(FILE *f, struct stack **source)
{
	int n;
	while (fscanf(f, "%d", &n) == 1)
	{
		assert((n >= -99) && (n <= 99));
		push(source, n);
	}
}


void print_stack(const struct stack *source)
{
	while (source)
	{
		printf("%d ", source->value);
		source = source->prev;
	}
}

void free_stack(struct stack *source)
{
	struct stack *tmp = source;
	while (tmp)
	{
		tmp = source->prev;
		pop(&source);
	}
}


void push_low(struct stack **stack_low, const int value)
{
	if (*stack_low)
	{
		push(stack_low, value);
	}
	else
	{
		struct stack *need = malloc(sizeof(struct stack));
		need->value = value;
		need->prev = (*stack_low)->prev->prev;
		
		(*stack_low)->prev = need;
		*stack_low = need;
	}
}


void push_high(struct stack **stack_high, const int value)
{
	if (*stack_high)
	{
		push(stack_high, value);
	}
	else
	{
		struct stack *need = malloc(sizeof(struct stack));
		need->value = value;
		need->prev = *stack_high;
		
		*stack_high = need;
	}
}


void insert(struct stack **stack_low, struct stack **stack_high, const struct *source, const int in_num)
{
	if (source == NULL)
		exit(0);
	
	int value;
	while (source)
	{
		value = source->value;
		
		if (value < in_num)
			push_low(stack_low, value);
		else
			push_high(stack_high, value);

		source = source->prev;
	}
}


void save_stack(FILE *f, const stack *stack_low, const stack *stack_high)
{
	// edit here
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error #1: Command has not enough parameters!\n");
		return -1;
	}

	FILE *f = fopen(argv[1], "r");
	if (!f)
	{
		printf("Error #2: File does not exist!\n");
		return -2;
	}

	struct stack *source = NULL;
	read_data(f, &source);
	fclose(f);

	print_stack(source);


	{
		int in_num;
		printf("\nInput in_num: ");
		scanf("%d", &in_num);

		FILE *f = fopen(argv[2], "w")

		assert(f);

		struct stack *stack_low = NULL, *stack_high = NULL;
		
		insert(&stack_low, &stack_high, source, in_num);
		
		save_stack(f, stack_low, stack_high);

		fclose(f);

		free_stack(stack_low);
		free_stack(stack_high);
	}

	free_stack(source);
	return 0;
}