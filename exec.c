#include "monty.h"

/**
 * execute_code - to execute the opcode
 * @stack_: head linked list - stack
 * @count: the line counter
 * @file_: pointer to monty file
 * @info: line info
 * Return: void
 */

int execute_code(char *info, stack_t **stack_, unsigned int count, FILE *file_)
{
	instruction_t op_st[] = {
		{"push", push_code}, {"pall", pall_code}, {"pint", pint_code},
		{"pop", pop_code},
		{"swap", swap_code},
		{"add", add_code},
		{"nop", nop_code},
		{"sub", sub_code},
		{"div", div_code},
		{"mul", mul_code},
		{"mod", mod_code},
		{"pchar", pchar_code},
		{"pstr", pstr_code},
		{"rotl", rotl_code},
		{"rotr", rotr_code},
		{"queue", queue_code},
		{"stack_", stack_code},
		{NULL, NULL}
	};
	unsigned int k = 0;
	char *op_c;

	op_c = strtok(info, " \n\t");
	if (op_c && op_c[0] == '#')
		return (0);
	bus_.arg = strtok(NULL, " \n\t");
	while (op_st[k].opcode && op_c)
	{
		if (strcmp(op_c, op_st[k].opcode) == 0)
		{	op_st[k].f(stack_, count);
			return (0);
		}
		k++;
	}
	if (op_c && op_st[k].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op_c);
		fclose(file_);
		free(info);
		fr_stack(*stack_);
		exit(EXIT_FAILURE); }
	return (1);
}
