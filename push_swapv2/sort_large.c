#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	num;

	size = stack_size(*stack_a);
	i = 0;
	while (!is_sorted(*stack_a))
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->index;
			if ((num >> i) & 1)
				ra(stack_a, 1);
			else
				pb(stack_b, stack_a, 1);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, 1);
		i++;
	}
}
