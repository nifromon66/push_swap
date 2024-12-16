/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:40:03 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/15 22:17:55 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_input(int argc, char **array)
{
    int     i;
    char    *str;

    i = 1;
    while (i < argc)
    {
        str = array[i];
        if (str == NULL)
            return (-1);
        if (*str == ' ' || (*str > 8 && *str < 14))
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

// Function to check if an argument of the list already exist
int check_double(int data, t_stack *head)
{
    t_stack *current;

    
    if (!head)
        return (0);
    current = head;
    if (current->data == data)
        return (-1);
    current = current->next;
    while (current != head)
    {
        if (current->data == data)
            return (-1);
        current = current->next;
    }
    return (0);
}

// Function to check if the input fits in a int
int is_int(long n)
{
    if (n < -2147483648 || n > 2147483647)
        return (-1);
    return (0);
}

static int	is_white_space(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

long	ft_atoi_long(const char *nptr)
{
	size_t	i;
	size_t	res;
	size_t	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_white_space(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((nptr[i] != '\0') && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}