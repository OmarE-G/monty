#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err(6, line_number);
	printf("%d\n", (*stack)->n);
}



/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

