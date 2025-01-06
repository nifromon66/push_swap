/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:56:38 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:12:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to push the first element of the stack b to the stack a
void	pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	write(1, "pa\n", 3);
	ouroboros_move_node(b, a, *b);
}

// Function to push the first element of the stack a to the stack b
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	write(1, "pb\n", 3);
	ouroboros_move_node(stack_a, stack_b, *stack_a);
}
