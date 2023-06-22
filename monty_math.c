#include "monty.h"

/**
 * m_sub - subs the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: number of the line
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sub;
}
