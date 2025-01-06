/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ouroboros_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:30:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:12:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to move a node from the stack origin
// to the top of the stack dest
void	ouroboros_move_node(t_stack **origin, t_stack**dest, t_stack *node)
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
	if (!*dest)
	{
		*dest = node;
		node->next = node;
		node->previous = node;
	}
	else
	{
		node->next = *dest;
		node->previous = (*dest)->previous;
		(*dest)->previous->next = node;
		(*dest)->previous = node;
		*dest = node;
	}
}

// Function to find the next element in the stack
// which value is higher than the value of node
t_stack	*ouroboros_find_next_higher(t_stack *head, t_stack *node)
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
