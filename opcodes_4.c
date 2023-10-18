#include "monty.h"


/**
 * mod - divide the top two values of the stack and find the remainder
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void mod(stack_t **stack, unsigned int line)
{
	char *err1, *err2;
	stack_t *tmp;

	err1 = "can't mod, stack too short";
	err2 = "division by zero";
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: %s\n", line, err1);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: %s\n", line, err2);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	(*stack)->next->n = ((*stack)->next->n % (*stack)->n);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * hash - comments
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void hash(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

