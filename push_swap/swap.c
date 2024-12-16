/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:37:42 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/15 20:59:50 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    swap_a(t_stack **stack_a)
{
    int result;
    
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return (-1);
    result = swap_nodes(stack_a, *stack_a, (*stack_a)->next);
    return(result);
}

int    swap_b(t_stack **stack_b)
{
    int result;
    
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return (-1);
    result = swap_nodes(stack_b, *stack_b, (*stack_b)->next);
    return(result);
}

int    swap_ab(t_stack **stack_a, t_stack **stack_b)
{
    int result;

    result = 0;
    result += swap_a(stack_a);
    result += swap_b(stack_b);
    if (result != 0)
        return (-1);
    return (0);
}