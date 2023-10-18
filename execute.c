#include "monty.h"
/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poitner to monty file
 *
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", tlcpush}, {"pall", tlcpall}, {"pint", tlcpint},
		{"pop", tlcpop},
		{"swap", tlcswap},
		{"add", tlcadd},
		{"nop", tlcnop},
		{"sub", tlcsub},
		{"div", tlcdiv},
		{"mul", tlcmul},
		{"mod", tlcmod},
		{"pchar", tlcpchar},
		{"pstr", tlcpstr},
		{"rotl", tlcrotl},
		{"rotr", tlcrotr},
		{"queue", tlcqueue},
		{"stack", tlcstack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
