/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:51:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:57 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to push the first element of the stack b to the stack a
void	silent_pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	Ouroboros_move_node(b, a, *b);
}

// Function to push the first element of the stack a to the stack b
void	silent_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	Ouroboros_move_node(stack_a, stack_b, *stack_a);
}
