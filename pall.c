#include "monty.h"
/**
 * tlcpall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void tlcpall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
