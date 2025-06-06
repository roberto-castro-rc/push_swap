/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:34:05 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/06/02 18:34:05 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print_op)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	if (print_op)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b, int print_op)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_b = second;
	if (print_op)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print_op)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print_op)
		ft_putendl_fd("ss", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print_op)
{
	t_stack	*node_to_push;

	if (!stack_b || !*stack_b)
		return ;
	node_to_push = *stack_b;
	*stack_b = node_to_push->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node_to_push->prev = NULL;
	node_to_push->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = node_to_push;
	*stack_a = node_to_push;
	if (print_op)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a, int print_op)
{
	t_stack	*node_to_push;

	if (!stack_a || !*stack_a)
		return ;
	node_to_push = *stack_a;
	*stack_a = node_to_push->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node_to_push->prev = NULL;
	node_to_push->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = node_to_push;
	*stack_b = node_to_push;
	if (print_op)
		ft_putendl_fd("pb", 1);
}
