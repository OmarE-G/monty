#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - code_operation and its function
 * @code_operation: the code_operation
 * @f: function to handle the code_operation
 *
 * Description: code_operation and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *code_operation;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*Error hanlding*/
void err(int error_code, ...);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Stack operations*/
stack_t *node_create(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);


/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);


/*file operations*/
void file_open(char *file_name);
int parse_line(char *buffer, int line_number, int type);
void read_open(FILE *);
int len_chars(FILE *);
void chose_fun(char *, char *, int, int);

void call_fun(op_func, char *, char *, int, int);




#endif
