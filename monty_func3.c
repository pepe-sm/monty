#include "monty.h"

/**
 * op_tofunc - chooses the correct function based on the opcode
 * @op: opcode
 *
 * Return: function attached to opcode
 */
void (*op_tofunc(char *op))(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;

	instruction_t opcodes[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", nop},
		{"sub", m_sub},
		{NULL, NULL}
		};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, op) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * free_stack - frees stack
 * @stack: pointer to stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * _isdigit - checks for digit
 * @str: string input to be checked
 *
 * Return: 0 if digit, 1 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		str[0] = '0';

	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
