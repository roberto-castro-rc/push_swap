#include "push_swap.h"

void	rra(t_stack **stack_a, int print_op)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = stack_last(*stack_a);
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	else
		(*stack_a)->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = last;
	*stack_a = last;
	if (print_op)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b, int print_op)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = stack_last(*stack_b);
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	else
		(*stack_b)->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = last;
	*stack_b = last;
	if (print_op)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print_op)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print_op)
		ft_putendl_fd("rrr", 1);
}
