/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:01:11 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 01:01:28 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to shift all the elements of stack a down by one position
void	rra(t_stack **a)
{
	if (!a || !*a || !(*a)->previous)
		return ;
	write(1, "rra\n", 4);
	*a = (*a)->previous;
}

// Function to shift all the elements of stack b down by one position
void	rrb(t_stack **b)
{
	if (!b || !*b || !(*b)->previous)
		return ;
	write(1, "rrb\n", 4);
	*b = (*b)->previous;
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
void	rrr(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	write(1, "rrr\n", 4);
	*a = (*a)->previous;
	*b = (*b)->previous;
}