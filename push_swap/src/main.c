/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:08:57 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 01:09:13 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Main function to sort the stack_a
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (check_input(args) == -1)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	a = dclst_load(args);
	if (a == NULL)
		return (clear_all(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	push_swap(&a, &b);
	if (!is_sorted(a, dclst_count_nodes(a)) || b)
		write(1, "Sort has failed\n", 16);
	clear_all(&a, &b, args, ac);
	return (0);
}