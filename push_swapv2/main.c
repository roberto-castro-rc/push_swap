#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!is_valid_input(argc, argv))
		exit_error();
	populate_stack_a(&stack_a, argc, argv);
	assign_indices(stack_a);
	if (is_sorted(stack_a))
	{
		stack_clear(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	populate_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	long	num;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error();
		new_node = stack_new((int)num);
		stack_add_back(stack_a, new_node);
		i++;
	}
}

static t_stack	*find_next_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min_val;

	min_node = NULL;
	min_val = LONG_MAX;
	while (stack)
	{
		if (stack->index == -1 && (long)stack->value < min_val)
		{
			min_val = (long)stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	assign_indices(t_stack *stack_a)
{
	int		index;
	t_stack	*min_node;

	index = 0;
	min_node = find_next_min(stack_a);
	while (min_node)
	{
		min_node->index = index++;
		min_node = find_next_min(stack_a);
	}
}
