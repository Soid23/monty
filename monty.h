#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/************monty bytecode functions*******/
void push(stack_t **head, unsigned int n);
void nah_pall(stack_t **head, unsigned int number);
void pint(stack_t **stack, unsigned int line_number);
void nah_pop(stack_t **head, unsigned int d);

/**********not-monty function****/
int is_number(const char *str);
void parse_line(char *line, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void _swap(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pall(stack_t **doubly, unsigned int cline);
void _push(stack_t **doubly, unsigned int cline);
#endif
