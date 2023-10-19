#include "monty.h"

/**
 * enqueue - add node to the end of the stack
 * @stack: stack frame
 * @new: new node to insert
 * Return: void
 */

void enqueue(stack_t **stack, stack_t *new)
{
	stack_t *tmp;
	int i;

	if (infoTray.idx == 0)
	{
		new->next = *stack;
		new->prev = NULL;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
		infoTray.idx++;
	}
	tmp = *stack;
	for (i = 1; tmp && i < infoTray.idx; i++)
		tmp = tmp->next;
	new->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = new;
	new->prev = tmp;
	tmp->next = new;
	infoTray.idx++;
}
