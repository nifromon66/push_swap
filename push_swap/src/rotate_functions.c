/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:58:21 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:11:05 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to shift all the elements of stack a up by one position
void	ra(t_stack **a)
{
	if (!a || !*a || *a == (*a)->next)
		return ;
	write(1, "ra\n", 3);
	*a = (*a)->next;
}

// Function to shift all the elements of stack b up by one position
void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	if (!b || !*b || *b == (*b)->next)
		return ;
	*b = (*b)->next;
}

// Function to shift all the elements of stack a up by one position
// and shift all the elements of stack b up by one position
void	rr(t_stack **a, t_stack **b)
{
	if (!a || !b || !*a || !*b)
		return ;
	write(1, "rr\n", 3);
	*a = (*a)->next;
	*b = (*b)->next;
}
