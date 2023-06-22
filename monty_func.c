#include "monty.h"

/**
 * m_push - adds to the stack
 * @stack: points to stack
 * @line_number: line number
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	char *i = NULL;
	unsigned int n = 0;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = strtok(NULL, DELIM);
	if (!i || _isdigit(i) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(i);

	temp->n = n;
	temp->prev = NULL;
	temp->next = *stack;

	if (temp->next != NULL)
		(temp->next)->prev = temp;
	*stack = temp;
}

/**
 * m_pall - outputs element of stack
 * @stack: points to stack
 * @line_number: literally line umber
 */
void m_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *value = *stack;

	while (value)
	{
		printf("%d\n", value->n);
		value = value->next;
	}
}

/**
 * m_pint - outputs element at top of list
 * @stack: points to stack
 * @line_number: number of line
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * m_pop - delete elemnt at top of stack
 * @stack: points to stack
 * @line_number: line number
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
