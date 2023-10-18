#include "monty.h"

/**
 * sub - sub the top two values of the stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void sub(stack_t **stack, unsigned int line)
{
	char *err;
	stack_t *tmp;

	err = "can't sub, stack too short";
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
	(*stack)->next->n = ((*stack)->next->n - (*stack)->n);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * div - divide the top two values of the stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void div(stack_t **stack, unsigned int line)
{
	char *err1, *err2;
	stack_t *tmp;

	err1 = "can't div, stack too short";
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
	(*stack)->next->n = ((*stack)->next->n / (*stack)->n);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * mul - multiply the top two values of the stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void mul(stack_t **stack, unsigned int line)
{
	char *err;
	stack_t *tmp;

	err = "can't mul, stack too short";
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
	(*stack)->next->n = ((*stack)->next->n * (*stack)->n);
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
