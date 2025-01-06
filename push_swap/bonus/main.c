/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:56:10 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:57:44 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Main function test the instructions to sort the stack a
// Return "OK" if the stack is sorted, "KO" if not,
// or "Error" if there is an error
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
		args = av +1;
	if (check_input(args) == -1)
		return (big_crunch(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	a = big_bang(args);
	if (a == NULL)
		return (big_crunch(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	if (checker(&a, &b) < 0)
		return (big_crunch(&a, &b, args, ac), write(2, "Error\n", 6), 2);
	if (!is_sorted(a, Ouroboros_count_nodes(a)) || b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	big_crunch(&a, &b, args, ac);
	return (0);
}
