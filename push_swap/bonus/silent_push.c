/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:51:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 03:52:22 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to push the first element of the stack b to the stack a
void	quiet_pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	dclst_move_node(b, a, *b);
}

// Function to push the first element of the stack a to the stack b
void	quiet_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	dclst_move_node(stack_a, stack_b, *stack_a);
}