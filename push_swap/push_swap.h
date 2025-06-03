/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:01:28 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/06/02 19:01:40 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					main(int argc, char **argv);
int					is_valid_input(int argc, char **argv);
int					is_sorted(t_stack *stack_a);
void				assign_indices(t_stack *stack_a);

void				exit_error(void);

t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new_node);
t_stack				*stack_last(t_stack *stack);
int					stack_size(t_stack *stack);
void				stack_clear(t_stack **stack);
void				populate_stack_a(t_stack **stack_a, int argc, char **argv);

void				sa(t_stack **stack_a, int print_op);
void				sb(t_stack **stack_b, int print_op);
void				ss(t_stack **stack_a, t_stack **stack_b, int print_op);
void				pa(t_stack **stack_a, t_stack **stack_b, int print_op);
void				pb(t_stack **stack_a, t_stack **stack_b, int print_op);

void				ra(t_stack **stack_a, int print_op);
void				rb(t_stack **stack_b, int print_op);
void				rr(t_stack **stack_a, t_stack **stack_b, int print_op);

void				rra(t_stack **stack_a, int print_op);
void				rrb(t_stack **stack_b, int print_op);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print_op);

void				sort_three(t_stack **stack_a);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);

void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif
