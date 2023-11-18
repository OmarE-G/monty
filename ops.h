#ifndef OPS_H
#define OPS_H
#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * push - p
 * @value : das
 * @stack : stack
 */
void push(int value, stack_t **stack)
{
	stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;

	*stack = new_node;
}


/**
 * pop - pop
 */
void pop(void)
{

	printf("popped\n");
}


/**
 * pall - print
 * @stack: stack ptr
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * apply_operations - applies ops
 * @op: op code
 * @arg: argument
 * @ST: stack
 */
void apply_operations(char *op, char *arg, stack_t **ST)
{
	int num;

	if (ST == NULL)
		printf("null\n");
	if (arg != NULL)
		num = atoi(arg);

	if (!strcmp(op, "pop"))
		pop();
	else if (!strcmp(op, "pall"))
		pall(*ST);
	else if (!strcmp(op, "push"))
		push(num, ST);
}
#endif
