#include "ops.h"
/**
* isNumber - check if string is a number'
* @s: string
* Return: 1 or 0
*/
int isNumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}


/**
 * process_line - line fnc
 * @curr_line: x
 * @line: x
 * @ST: stack
 */
void process_line(char *curr_line, int line, stack_t *ST)
{
	int flag = 0;
	char *temp = curr_line, *curr_op, *curr_arg, *curr_word;

	do {
		curr_word = strtok(temp, " \t \n");
		temp = NULL;

		if (curr_word == NULL)
		{
			if (flag == 0)
				break;
			else if (flag == 1)
				printf("L%d: usage: push integer\n", line),	exit(EXIT_FAILURE);
		}

		if (flag == 0)
		{
			if ((strcmp(curr_word, "pop") == 0) ||
			(strcmp(curr_word, "push") == 0) || (strcmp(curr_word, "pall") == 0))
				curr_op = curr_word, flag  = 1;
			if (strcmp(curr_word, "push") != 0) /*no need to wait for argument*/
				flag = 2;
		}
		else if (flag == 1)
		{
			if (isNumber(curr_word))
				curr_arg = curr_word, flag = 2;

			else
				printf("L%d: usage: push integer\n", line), exit(EXIT_FAILURE);

		}
		if (flag == 2)
		{
			apply_operations(curr_op, curr_arg, ST);
			break;
		}

	} while (curr_word != NULL && flag != 2);

}


/**
* main - entry point
* @argc: number of args
* @args: arguments as strings
* Return: 0
*/

int main(int argc, char *args[])
{
	stack_t ST;
	FILE *f;
	char *curr_line;
	int line = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(args[1], "r");
	if (f == NULL)
	{
		printf("Error: Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}

	/*start proceessing file line by line*/
	curr_line = malloc(505);
	while (fgets(curr_line, 500, f))
	{
		line++;
		process_line(curr_line, line, &ST);
		/*look for opcode*/

	}
	return (0);
}
