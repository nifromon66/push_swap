/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:06:18 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:12:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to put the lowest element of stack a to the top
void	put_lowest_to_top(t_stack **a)
{
	t_stack	*lowest;
	int		len;

	lowest = ouroboros_find_min(*a);
	len = ouroboros_count_nodes(*a);
	if (lowest->index > len / 2)
	{
		while (lowest != *a)
			rra(a);
	}
	else
	{
		while (lowest != *a)
			ra(a);
	}
}

// Function to push node from stack b to stack a
void	push_node_to_a(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->better_up && node->target->better_up)
		while (node != *b && node->target != *a)
			rr(a, b);
	else if (!node->better_up && !node->target->better_up)
		while (node != *b && node->target != *a)
			rrr(a, b);
	while (node != *b)
	{
		if (node->better_up)
			rb(b);
		else
			rrb(b);
	}
	while (node->target != *a)
	{
		if (node->target->better_up)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

// Function to find the node with the lowest sort cost
t_stack	*find_cheapest_node(t_stack *b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		len;

	current = b;
	cheapest = b;
	len = ouroboros_count_nodes(b);
	while (len > 0)
	{
		if (current->sort_cost < cheapest->sort_cost)
			cheapest = current;
		current = current->next;
		len--;
	}
	return (cheapest);
}

// Function to push the "cheapest" element from stack b to stack a
// while keeping the stack a sorted
void	sort_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		initialize_variables_in_a(*a);
		initialize_variables_in_b(*a, *b);
		cheapest = find_cheapest_node(*b);
		push_node_to_a(a, b, cheapest);
	}
	put_lowest_to_top(a);
}

// Function to sort the stack_a
void	push_swap(t_stack **a, t_stack **b)
{
	int		len;

	if (!a || !*a)
		return ;
	len = ouroboros_count_nodes(*a);
	if (is_sorted(*a, len))
		return ;
	if (len == 2)
		sort_2a(a);
	else if (len == 3)
		sort_3(a);
	else
	{
		while (len-- > 3)
			pb(a, b);
		sort_3(a);
		sort_from_b_to_a(a, b);
	}
}
