#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swap;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}

/**
 * _rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;

	UNUSED(line_number);

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (end->next)
		end = end->next;

	end->next = *stack;
	(*stack)->prev = end;
	*stack = (*stack)->next;
	end->next->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * _rotr - prints the char at the top of the stack, followed
 * by a new line
 * @stack: stack
 * @line_number: line_number
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	UNUSED(line_number);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (top->next)
		top = top->next;

	top->prev->next = NULL;
	top->next = *stack;
	top->prev = NULL;
	(*stack)->prev = top;
	*stack = top;
}
