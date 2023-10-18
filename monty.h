#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} _stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(_stack_t **stack, unsigned int line_number);
} instruction_t;


char **_strtok(char *line);
int tokCount(char *line, char *sep);
void push(_stack_t **stack, int data);
int check_valid_int(char *str);
void process_op(char **tokens, unsigned int line, _stack_t **stack, FILE *);
void swap(_stack_t **stack, unsigned int line);
void pop(_stack_t **stack, unsigned int line);
void pint(_stack_t **stack, unsigned int line);
void pall(_stack_t **stack, unsigned int line);
void push(_stack_t **stack, int n);
int stack_len(_stack_t *stack);
void nop(_stack_t **stack, unsigned int line);
void add(_stack_t **stack, unsigned int line);
void printTokens(char **tokens);
void freeMemory(char **tokens);
char *_strdup(char *src);
void freeStack(_stack_t *stack);
void pclean(char **, FILE *, _stack_t **);

#endif
