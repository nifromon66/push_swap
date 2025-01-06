/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:48:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:12:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to swap the first two elements of stack_a
void	silent_sa(t_stack **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	ouroboros_swap_nodes(a, *a, (*a)->next);
}

// Function to swap the first two elements of stack b
void	silent_sb(t_stack **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	ouroboros_swap_nodes(b, *b, (*b)->next);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
void	silent_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	ouroboros_swap_nodes(a, *a, (*a)->next);
	ouroboros_swap_nodes(b, *b, (*b)->next);
}
