#include "monty.h"

/**
 * comment - check for comment in the monty file (#)
 * @tokens: line tokens
 * Return: NULL or line tokens
 */

char **comment(char **tokens)
{
	if (tokens[0][0] == '#')
	{
		freeMemory(tokens);
		return (NULL);
	}
	return (tokens);
}
