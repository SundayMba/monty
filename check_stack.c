#include "monty.h"

/**
 * stack - check for opcode stack
 * @tokens: line tokens
 * Return: NULL or line tokens
 */

char **stack(char **tokens)
{
	if (strstr("stack", tokens[0]))
	{
		infoTray.state = "stack";
		infoTray.idx = -1;
		freeMemory(tokens);
		return (NULL);
	}
	return (tokens);
}
