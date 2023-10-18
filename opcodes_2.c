#include "monty.h"

/**
 * add - add the top two values of the stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void add(stack_t **stack, unsigned int line)
{
	char *err;
	stack_t *tmp;

	err = "can't add, stack too short";
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: %s\n", line, err);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	(*stack)->next->n = ((*stack)->n + (*stack)->next->n);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - no operation
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * stack_len - Get the length of the stack
 * @stack: pointer to the beginning of the stack frame
 * Return: stack length
 */

int stack_len(stack_t *stack)
{
	int len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
