#include "monty.h"

/**
 * file_open - fun to open a file
 * @file_name: the name of the file
 * Return: void
 */

void file_open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_open(fd);
	fclose(fd);
}


/**
 * file_open - reads a file
 * @fd: pointer to the file path 
 * Return: void
 */

void read_open(FILE *fd)
{
	int line_number, type = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		type = parse_line(buffer, line_number, type);
	}
	free(buffer);
}


/**
 * parse_line - fun to parse the line
 * @buffer: line from the file
 * @line_number: line number
 * @type: If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the code_operation is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int type)
{
	char *value , *code_operation;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	code_operation = strtok(buffer, delim);
	if (code_operation == NULL)
		return (type);
	value = strtok(NULL, delim);

	if (strcmp(code_operation, "queue") == 0)
		return (1);
	if (strcmp(code_operation, "stack") == 0)
		return (0);
	
	chose_fun(code_operation, value, line_number, type);
	return (type);
}
