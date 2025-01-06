/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_bang_theory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:47:26 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 00:51:18 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack	*big_bang(char **args)
{
	t_stack	*head;
	t_stack	*new;
	long	data;
	int		i;

	head = NULL;
	i = 0;
	while (args[i])
	{
		data = ft_atoi_long(args[i]);
		if (is_int(data) == 0 || has_double(head, (int) data) != 0)
			return (dclst_clear(&head), NULL);
		new = dclst_insert_node_end(&head, (int) data);
		if (!new)
			return (dclst_clear(&head), NULL);
		i++;
	}
	return (head);
}

// Function to clear stacks and args
void	big_crunch(t_stack **a, t_stack **b, char **args, int argc)
{
	int	i;

	if (a && *a)
		dclst_clear(a);
	if (b && *b)
		dclst_clear(b);
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}