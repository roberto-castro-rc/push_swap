#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	array[3];

	if (stack_size(*stack_a) != 3)
		return ;
	if (is_sorted(*stack_a))
		return ;
	array[0] = (*stack_a)->index;
	array[1] = (*stack_a)->next->index;
	array[2] = (*stack_a)->next->next->index;
	if (array[0] > array[1] && array[1] < array[2] && array[0] < array[2])
		sa(stack_a, 1);
	else if (array[0] > array[1] && array[1] > array[2])
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (array[0] > array[1] && array[1] < array[2] && array[0] > array[2])
		ra(stack_a, 1);
	else if (array[0] < array[1] && array[1] > array[2] && array[0] < array[2])
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (array[0] < array[1] && array[1] > array[2] && array[0] > array[2])
		rra(stack_a, 1);
}

static int	find_index_pos(t_stack *stack, int index_to_find)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index_to_find)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	push_index_to_b(t_stack **stack_a, t_stack **stack_b,
		int index_to_find)
{
	int	pos;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	pos = find_index_pos(*stack_a, index_to_find);
	size = stack_size(*stack_a);
	if (pos == -1)
		return ;
	while ((*stack_a)->index != index_to_find)
	{
		if (pos <= size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	pb(stack_b, stack_a, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push_index_to_b(stack_a, stack_b, 0);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push_index_to_b(stack_a, stack_b, 0);
	push_index_to_b(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
