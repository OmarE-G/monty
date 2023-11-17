#include <stdio.h>
#include "monty.h"

/**
 * push - p
 * @x:  das
 */
void push(char *x)
{
	int n = atoi(x);

	printf("pushed %d\n", n);
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
 */
void pall(void)
{
	printf("printing all\n");
}

/**
 * apply_operations - applies ops
 * @op: op code
 * @arg: argument
 */
void apply_operations(char *op, char *arg)
{
	int num;

	if (arg != NULL)
		num = atoi(arg);

	if (!strcmp(op, "pop"))
		pop();
	else if (!strcmp(op, "pall"))
		pall();
	else if (!strcmp(op, "push"))
		push(arg);
}
