/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:29:50 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/13 22:02:42 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to shift all the node's position one node higher for stack_a
int    rotate_a(t_stack **stack_a)
{
    if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
        return (-1);
    *stack_a = (*stack_a)->next;
    return (0);
}

// Function to shift all the node's position one node higher for stack_b
int    rotate_b(t_stack **stack_b)
{
    if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
        return (-1);
    *stack_b = (*stack_b)->next;
    return (0);
}

// Function to shift all the node's position one node higher for stack_a and _b
int    rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
    int result;

    result = 0;
    result += rotate_a(stack_a);
    result += rotate_b(stack_b);
    if (result != 0)
        return (-1);
    return (0);
}