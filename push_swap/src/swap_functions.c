/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:53:21 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to swap the first two elements of stack_a
void	sa(t_stack **a)
{
	if (!a || !*a || (*a)->next == *a)
		return ;
	write(1, "sa\n", 3);
	Ouroboros_swap_nodes(a, *a, (*a)->next);
}

// Function to swap the first two elements of stack b
void	sb(t_stack **b)
{
	if (!b || !*b || (*b)->next == *b)
		return ;
	write(1, "sb\n", 3);
	Ouroboros_swap_nodes(b, *b, (*b)->next);
}

// Function to swap the first two elements of stack_a
// and swap the first two elements of swap_b
void	ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	write(1, "ss\n", 3);
	Ouroboros_swap_nodes(a, *a, (*a)->next);
	Ouroboros_swap_nodes(b, *b, (*b)->next);
}
