#include "monty.h"

/**
 * main - main func to monty interpritation
 * @ac: argument count
 * @av: argument vector
 * Return: return 0 on success else exit status
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	char *buff = NULL, *op = NULL;
	stack_t *stack = NULL;
	size_t size = 0, line_number = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &size, fd) != -1)
	{
		line_number++;
		op = strtok(buff, DELIM);
		if (!op)
			continue;

		f = op_tofunc(op);
		if (!f)
		{
			fprintf(stderr, "L%lu: Instruction  not interprated %s\n", line_number, op);
			fclose(fd), free(buff), free_stack(stack), exit(EXIT_FAILURE);
		}

		f(&stack, line_number);
	}
	fclose(fd);
	free(buff);
	free_stack(stack);
	return (0);
}
