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
void process_line(char *curr_line, int line, stack_t **ST)
{
	char *temp = curr_line, *curr_op, *curr_arg = NULL, *curr_word;

		curr_word = strtok(temp, " \t \n\r");
		temp = NULL;

		if (curr_word == NULL)
			return;

		if ((strcmp(curr_word, "pop") == 0) ||
		(strcmp(curr_word, "push") == 0) || (strcmp(curr_word, "pall") == 0))
			curr_op = curr_word;
		else
		{
			printf("L%d: unknown instruction %s\n", line, curr_word);
			exit(EXIT_FAILURE);
		}
		if (strcmp(curr_word, "push") == 0)
		{
			curr_arg = strtok(temp, " \t \n\r");

			if (curr_arg == NULL || !isNumber(curr_arg))
				printf("L%d: usage: push integer\n", line),	exit(EXIT_FAILURE);
		}
		apply_operations(curr_op, curr_arg, ST);

}


/**
* main - entry point
* @argc: number of args
* @args: arguments as strings
* Return: 0
*/
int main(int argc, char *args[])
{
	FILE *f;
	char *curr_line;
	int line = 0;
	stack_t *ST = NULL;



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
	curr_line = malloc(1000);
	while (fgets(curr_line, 1000, f))
	{
		line++;
		process_line(curr_line, line, &ST);
		/*look for opcode*/

	}
	return (0);
}
