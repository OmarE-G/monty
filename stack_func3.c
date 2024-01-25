#include "monty.h"

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err(8, line_number, "mod");


	if ((*stack)->n == 0)
		err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err(8, line_number, "div");

	if ((*stack)->n == 0)
		err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the code_operation.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



