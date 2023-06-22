#include "monty.h"

/**
 * m_swap - swaps top 2 elements
 * @stack: points to stack
 * @line_number: line number
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * m_add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	m_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * nop - does nothing
 * @stack: points to stack
 * @line_number: number of the line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
