/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:15:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 17:12:44 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Function to check if the input is valid
int	check_input(char **args)
{
	int		i;
	char	*str;

	i = 0;
	while (args[i])
	{
		str = args[i];
		if (str == NULL)
			return (-1);
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			return (-1);
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (-1);
			str++;
		}
		i++;
	}
	return (0);
}

// Function to check if the input is an int
int	is_int(long n)
{
	if (n < -2147483648 || n > 2147483647)
		return (0);
	return (1);
}

// Function to check if the input has a double
int	has_double(t_stack *head, int data)
{
	t_stack	*current;

	if (!head)
		return (0);
	current = head;
	if (current->data == data)
		return (1);
	current = current->next;
	while (current != head)
	{
		if (current->data == data)
			return (1);
		current = current->next;
	}
	return (0);
}
