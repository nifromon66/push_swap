/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ouroboros_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:30:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to move a node from the stack origin
// to the top of the stack destination
void	Ouroboros_move_node(t_stack **origin, t_stack**destination, t_stack *node)
{
	if (node == *origin)
	{
		if ((*origin)->next == *origin)
			*origin = NULL;
		else
			*origin = node->next;
	}
	node->next->previous = node->previous;
	node->previous->next = node->next;
	if (!*destination)
	{
		*destination = node;
		node->next = node;
		node->previous = node;
	}
	else
	{
		node->next = *destination;
		node->previous = (*destination)->previous;
		(*destination)->previous->next = node;
		(*destination)->previous = node;
		*destination = node;
	}
}

// Function to find the next element in the stack
// which value is higher than the value of node
t_stack	*Ouroboros_find_next_higher(t_stack *head, t_stack *node)
{
	t_stack	*current;
	t_stack	*next_higher;

	if (!head || !node)
		return (NULL);
	current = node->next;
	next_higher = NULL;
	while (current != node)
	{
		if (current->data > node->data)
		{
			if (!next_higher || current->data < next_higher->data)
				next_higher = current;
		}
		current = current->next;
	}
	return (next_higher);
}
