#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int value;
	struct stack *prev;
};

struct stack *new(const int value);

void asc_insert(struct stack **stack_low, struct stack *new_node);

void dec_insert(struct stack **stack_high, struct stack *new_node);

void print_stack(const struct stack *stack_low, const struct stack *stack_high);

void free_stack(struct stack *source);

void fill_stack(struct stack **stack_l, struct stack **stack_h, const int border, const int value);

#endif