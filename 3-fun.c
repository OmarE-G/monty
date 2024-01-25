#include "monty.h"

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the code_operation.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @type: type specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int type)
{
	stack_t *node;
	int boool;
	int i;

	boool = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			boool = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = node_create(atoi(val) * boool);
		if (type == 0)
			func(&node, ln);
		if (type == 1)
			queue_add(&node, ln);
	}
	else
		func(&head, ln);
}

/**
 * chose_fun - function to chose the function
 * @code_operation: code_operation
 * @value: argument of code_operation
 * @type:  storage type. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void chose_fun(char *code_operation, char *value, int ln, int type)
{
	int i;
	int boool;

	instruction_t list_of_fun[] = {
		{"pop", pop_top},
		{"nop", nop},
		{"push", stack_add},
		{"pall", print_stack},
		{"pint", print_top},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"mod", mod_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{NULL, NULL}
	};

	if (code_operation[0] == '#')
		return;

	for (boool = 1, i = 0; list_of_fun[i].code_operation != NULL; i++)
	{
		if (strcmp(code_operation, list_of_fun[i].code_operation) == 0)
		{
			call_fun(list_of_fun[i].f, code_operation, value, ln, type);
			boool = 0;
		}
	}
	if (boool == 1)
		err(3, ln, code_operation);
}


