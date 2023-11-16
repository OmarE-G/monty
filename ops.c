#include <stdio.h>
#include "monty.h"


void push(int n);
void pop(void);
void pall(void);

/**
 * apply_operations - applies ops
 * @op: op code
 * @arg: argument
 */
void apply_operations(char *op, char *arg)
{
	int num = atoi(arg);

	if (op == "pop")
		pop();
	else if (op == "pall")
		pall();
	else if (op == "push")
		push(arg);
}