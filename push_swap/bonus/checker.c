/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:34:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 04:37:58 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"


// Function to choose which instruction to execute
// Returns 0 if the instruction is executed, -1 if the instruction is not found
int	dispatch(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		quiet_sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		quiet_sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		quiet_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		quiet_pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		quiet_pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		quiet_ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		quiet_rb(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		quiet_rr(a, b);
    else if (ft_strncmp(line, "rra\n", 4) == 0)
		quiet_rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		quiet_rrb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		quiet_rrr(a, b);
	else
		return (-1);
	return (0);
}

// Function to check the instruction is valid
// Returns 0 if the instruction is valid, -1 if not
int	instruction(t_stack **a, t_stack **b, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len != 3 && len != 4)
		return (-1);
	if (dispatch(a, b, line) < 0)
        return (-1);
	return (0);
}

// Function to test the instructions to sort the stack a
int	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (instruction(a, b, line) < 0)
			return (free(line), -1);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (0);
}