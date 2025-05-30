#include "push_swap.h"

void	ra(t_stack **stack_a, int print_op)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = stack_last(*stack_a);
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print_op)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b, int print_op)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = stack_last(*stack_b);
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print_op)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print_op)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print_op)
		ft_putendl_fd("rr", 1);
}
