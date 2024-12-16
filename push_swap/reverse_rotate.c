/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:47:06 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/13 22:03:19 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to shift all the node's position one node lower for stack_a
int    reverse_rotate_a(t_stack **stack_a)
{
    if (!stack_a || !*stack_a || (*stack_a)->previous == *stack_a)
        return (-1);
    *stack_a = (*stack_a)->previous;
    return (0);
}

// Function to shift all the node's position one node lower for stack_b
int    reverse_rotate_b(t_stack **stack_b)
{
    if (!stack_b || !*stack_b || (*stack_b)->previous == *stack_b)
        return (-1);
    *stack_b = (*stack_b)->previous;
    return (0);
}

// Function to shift all the node's position one node lower for stack_a and _b
int    reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
    int result;

    result = 0;
    result += reverse_rotate_a(stack_a);
    result += reverse_rotate_b(stack_b);
    if (result != 0)
        return (-1);
    return (0);
}