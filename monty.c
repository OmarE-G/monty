#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "monty.h"
/**
* isNumber - check if string is a number'
* @s: string
* Return: 1 or 0
*/
int isNumber(char *s)
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return 0;
    }
    return 1;
}


/**
* main - entry point'
* @argc: number of args
* @args: arguments as strings
* Return: 0
*/
int main(int argc, char *args[])
{
	FILE *f = fopen(args[1], "r");
	char *curr_line;
	char *curr_word;
	char *curr_op, *curr_arg;
	char *temp;
	int flag = 0;
	/*0 - not started , 1- opcode found, 2- argument found*/

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);

	}
	if (f == NULL)
	{
		printf("Error: Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}

	/*start proceessing file line by line*/

	while (fgets(curr_line, 500, f))
	{
		flag = 0;
		temp = curr_line;
		/*look for opcode*/
		do {
			curr_word = strtok(temp, " \t");
			temp = NULL;
			if (!flag)
			{
				if (curr_word == "pall" || curr_word == "push" || curr_word == "pop")
				{
					curr_op = curr_word, flag  = 1;

					if(curr_word != "push") /*no need to wait for argument*/
						flag = 2;
				}
			}
			else if (flag == 1)
			{
				if (isNumber(curr_word))
					curr_arg = curr_word, flag = 2;

				else
				{
					printf("L<%d>: usage: push integer\n", __LINE__);
					exit(EXIT_FAILURE);
				}
			}

			if(flag == 2)
			{
				apply_operations(curr_op, curr_arg);
				break;
				
			}
		} while (curr_word && flag != 2);

	}

	return (0);
}