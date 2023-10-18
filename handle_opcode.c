#include "monty.h"

/**
 * process_opcode - process operation codes
 * @tokens: opcode and it argument
 * @line: opcode line number
 * @stack: pointer to pointer that points to stack
 * Return: void
 */

void process_opcode(char **tokens, unsigned int line, _stack_t **stack)
{
	int opcode_state = 0, valid, arg, i;
	instruction_t instruction[] = {
		{"pop", pop}, {"pall", pall}, {"nop", nop},
		{"add", add}, {"swap", swap}, {"pint", pint}, {NULL, NULL}
	};

	/* printTokens(tokens); */
	for (i = 0; instruction[i].opcode && tokens[0]; i++)
	{
		if (strstr(instruction[i].opcode, tokens[0]) != NULL)
		{
			freeMemory(tokens);
			instruction[i].f(stack, line);
			opcode_state = 1;
			break;
		}
	}
	if (opcode_state == 1)
		return;
	if (strstr("push", tokens[0]))
	{
		valid = check_valid_int(tokens[1]);
		if (valid == -1)
		{
			freeMemory(tokens);
			fprintf(stderr, "L%u: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
		arg = atoi(tokens[1]);
		freeMemory(tokens);
		push(stack, arg);
		return;
	}
	freeMemory(tokens);
	fprintf(stderr, "L%u: unknown instruction %s\n", line, tokens[0]);
	exit(EXIT_FAILURE);
}

/**
 * check_valid_int - check for valid int in string
 * @str: string
 * Return: -1 if failed, 0 if valid
 */

int check_valid_int(char *str)
{
	char *numbers;
	int i;

	numbers = "0123456789";
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (strchr(numbers, str[i]) == NULL)
			return (-1);
	}
	return (0);
}
