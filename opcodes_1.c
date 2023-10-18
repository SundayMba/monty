#include "monty.h"

/**
 * push - push a node to the stack frame memory
 * @stack: pointer to the pointer to head stack
 * @n: data to create new node
 * Return: void
 */

void push(stack_t **stack,  int n)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "%s\n", "Error: malloc failed");
		if (infoTray.token != NULL)
			freeMemory(infoTray.token);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	/* insert at the beginning of the stack */
	new->next = *stack;
	new->prev = NULL;
	/* set up the prev if stack is not empty */
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - print everything on stack frame
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	(void)line;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print the value at the top stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void pint(stack_t **stack, unsigned int line)
{
	char *err;

	err = "can't pint, stack empty";
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: %s\n", line, err);
		if (infoTray.token != NULL)
			freeMemory(infoTray.token);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove the value at the top stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void pop(stack_t **stack, unsigned int line)
{
	char *err;
	stack_t *tmp;

	err = "can't pop an empty stack";
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: %s\n", line, err);
		if (infoTray.token != NULL)
			freeMemory(infoTray.token);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swap the top two values of the stack
 * @line: line number
 * @stack: pointer to the beginning of the stack frame
 * Return: void
 */

void swap(stack_t **stack, unsigned int line)
{
	char *err;
	int tmp;

	err = "can't swap, stack too short";
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: %s\n", line, err);
		if (infoTray.token != NULL)
			freeMemory(infoTray.token);
		if (infoTray.stack != NULL)
			freeStack(infoTray.stack);
		if (infoTray.file != NULL)
			fclose(infoTray.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

