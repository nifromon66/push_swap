/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:49:50 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 03:50:03 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to shift all the elements of stack a up by one position
void	quiet_ra(t_stack **a)
{
	if (!a || !*a || *a == (*a)->next)
		return ;
	*a = (*a)->next;
}

// Function to shift all the elements of stack b up by one position
void	quiet_rb(t_stack **b)
{
	if (!b || !*b || *b == (*b)->next)
		return ;
	*b = (*b)->next;
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
void	quiet_rr(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
}