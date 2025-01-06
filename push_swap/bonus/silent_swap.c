/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:48:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:57 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to swap the first two elements of stack_a
void	silent_sa(t_stack **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	Ouroboros_swap_nodes(a, *a, (*a)->next);
}

// Function to swap the first two elements of stack b
void	silent_sb(t_stack **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	Ouroboros_swap_nodes(b, *b, (*b)->next);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
void	silent_ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	Ouroboros_swap_nodes(a, *a, (*a)->next);
	Ouroboros_swap_nodes(b, *b, (*b)->next);
}
