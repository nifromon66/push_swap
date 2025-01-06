/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:50:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 03:50:59 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to shift all the elements of stack a down by one position
void	quiet_rra(t_stack **a)
{
	if (!a || !*a || !(*a)->previous)
		return ;
	*a = (*a)->previous;
}

// Function to shift all the elements of stack b down by one position
void	quiet_rrb(t_stack **b)
{
	if (!b || !*b || !(*b)->previous)
		return ;
	*b = (*b)->previous;
}

// Function to shift all the elements of stack a down by one position
// and shift all the elements of stack b down by one position
void	quiet_rrr(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	*a = (*a)->previous;
	*b = (*b)->previous;
}