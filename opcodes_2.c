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
 * pchar - print the value at the top stack as ascii
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line)
{
	char *err1, *err2;
	stack_t *tmp;

	err1 = "can't pchar, stack empty";
	err2 = "can't pchar, value out of range";
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: %s\n", line, err1);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: %s\n", line, err2);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * pstr - print all value of  stack as ascii
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp && tmp->n != 0 && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotate stack by reversing only it top element
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line)
{
	stack_t *last;
	(void)line;

	if (stack_len(*stack) < 2)
		return;
	last = *stack;
	first = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
	first->prev = last;
}

