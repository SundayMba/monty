#include "monty.h"

/**
 * queue - check for opcode queue
 * @tokens: line tokens
 * Return: NULL or line tokens
 */

char **queue(char **tokens)
{
	if (strstr("queue", tokens[0]))
	{
		infoTray.state = "queue";
		freeMemory(tokens);
		return (NULL);
	}
	return (tokens);
}
