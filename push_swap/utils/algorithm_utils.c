/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:11:46 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 01:12:04 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to see if the first len nodes of stack are sorted
int	is_sorted(t_stack *stack, int len)
{
	t_stack	*index;

	index = stack;
	while (len > 1)
	{
		if (index->data > index->next->data)
			return (0);
		index = index->next;
		len--;
	}
	return (1);
}

// Function to see if if the first len nodes of stack are reverse sorted
int	is_reverse_sorted(t_stack *stack, int len)
{
	t_stack	*index;

	index = stack;
	while (len > 1)
	{
		if (index->data < index->next->data)
			return (0);
		index = index->next;
		len--;
	}
	return (1);
}

// Function to sort the 2 elements at the top of a stack a
void	sort_2a(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

// Function to sort by reverse the 2 elements at the top of a stack b
void	sort_2b(t_stack **b)
{
	if (!b || !*b)
		return ;
	if ((*b)->data < (*b)->next->data)
		sb(b);
}

// Function to sort stack a with 3 or less elements
void	sort_3(t_stack **a)
{
	if (!a || !*a || dclst_count_nodes(*a) < 3)
		return ;
	if ((*a)->data < (*a)->next->data && (*a)->data < (*a)->previous->data)
	{
		if ((*a)->next->data > (*a)->previous->data)
		{
			sa(a);
			ra(a);
		}
	}
	else if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->previous->data)
	{
		ra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else
	{
		if ((*a)->previous->data < (*a)->data)
			rra(a);
		else
			sa(a);
	}
}