#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stack
{
	int value;
	struct stack *prev;
};

void create(struct stack *);

int is_empty(struct stack *);

int pop(struct stack **source);

void read_data(FILE *, struct stack **);

void print_stack(const struct stack *);

void push_low(struct stack **stack_low, const int value);

void push_high(struct stack **stack_high, const int value);

void insert(struct stack **stack_low, struct stack **stack_high, const struct *source, const int in_num);

void save_stack(FILE *f, const stack *stack_low, const stack *stack_high);

#endif