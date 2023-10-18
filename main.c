#include "monty.h"

/**
 * main - entry point of the program
 * @argv: a vector of the input argument
 * @argc: a count of the argument
 * Return: 0 - success or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	int line_number = 0;
	char opcode[SIZE], *line, **line_tokens;
	FILE *file;
	stack_t *stack = NULL;
	content_t infoTray = {NULL, NULL, NULL};

	/* check for valid item argument and handle errors */
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	/* open the monty bytecode file for reading and handle errors */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = fgets(opcode, SIZE, file);
	infoTray.file = file;
	infoTray.stack = &stack;
	while (feof(file) == 0 && line != NULL)
	{
		line_number++;
		/* tokenize the string line */
		line_tokens = _strtok(line);
		infoTray.token = line_tokens;
		/* printTokens(line_tokens); */
		if (line_tokens != NULL)
			process_op(line_tokens, line_number, &stack, file);
		line = fgets(opcode, SIZE, file);
	}
	fclose(file);
	freeStack(&stack);
	return (0);
}

/**
 * _strtok - tokenize the line of string
 * @line: line of string
 * Return: pointer to array of string tokens or NULL
 */

char **_strtok(char *line)
{
	char *sep, *token, **line_token;
	int token_count;

	sep = " \n\t";
	if (line == NULL)
		return (NULL);
	token_count = tokCount(_strdup(line), sep);
	if (token_count <= 0)
		return (NULL);
	line_token = (char **)malloc(sizeof(char *) * (token_count + 1));
	if (line_token == NULL)
		return (NULL);
	token = strtok(line, sep);
	token_count = 0;
	while (token != NULL)
	{
		line_token[token_count++] = _strdup(token);
		token = strtok(NULL, sep);
	}
	line_token[token_count] = NULL;
	return (line_token);
}

/**
 * tokCount - count the number of tokens
 * @line: line of string
 * @sep: seperators
 * Return: number of tokens or -1
 */

int tokCount(char *line, char *sep)
{
	int line_count;
	char *token;

	line_count = 0;
	token = strtok(line, sep);
	while (token != NULL)
	{
		line_count++;
		token = strtok(NULL, sep);
	}
	free(line);
	return (line_count);
}

/**
 * freeMemory - free a doubled pointer memory
 * @tokens: pointer to an array of tokens
 * Return: void
 */

void freeMemory(char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		for (i = 0; tokens[i]; i++)
		{
			if (tokens[i] != NULL)
				free(tokens[i]);
		}
		free(tokens);
	}
}

/**
 * printTokens - print tokens
 * @tokens: tokens to print
 * Return: void
 */

void printTokens(char **tokens)
{
	if (tokens != NULL)
	{
		while (*tokens)
			printf("%s ", *tokens++);
		printf("\n");
	}
}
