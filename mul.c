#include "monty.h"
/**
 * tlcmul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void tlcmul(stack_t **head, unsigned int counter)
{
	stack_t *newnode;
	int len = 0, aux;

	newnode = *head;
	while (newnode)
	{
		newnode = newnode->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	newnode = *head;
	aux = newnode->next->n * newnode->n;
	newnode->next->n = aux;
	*head = newnode->next;
	free(newnode);
}
