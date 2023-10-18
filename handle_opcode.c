#include "monty.h"

/**
 * process_op - process operation codes
 * @tokens: opcode and it argument
 * @line: opcode line number
 * @stack: pointer to pointer that points to stack
 * Return: void
 */

void process_op(char **tokens, unsigned int line, _stack_t **stack, FILE *file)
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
			fprintf(stderr, "L%u: usage: push integer\n", line);
			pclean(tokens, file, stack);
			exit(EXIT_FAILURE);
		}
		arg = atoi(tokens[1]);
		freeMemory(tokens);
		push(stack, arg);
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line, tokens[0]);
	pclean(tokens, file, stack);
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

/**
 * _strdup - string duplication
 * @src: source string
 * Return: a pointer to the destination string
 */

char *_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (strlen(src) + 1));
	if (dest)
		strcpy(dest, src);
	return (dest);
}

/**
 * freeStack - free the stack memory
 * @stack: pointer to the stack
 * Return: void
 */

void freeStack(_stack_t *stack)
{
	_stack_t *tmp;

	if (stack == NULL)
		return;
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * pclean - clean the program before exiting
 * @tokens: tokens memory
 * @file: file memory
 * @stack: stack memory
 * Return: void
 */

void pclean(char **tokens, FILE *file, _stack_t **stack)
{
	freeMemory(tokens);
	fclose(file);
	freeStack(*stack);
}

