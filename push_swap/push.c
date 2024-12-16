/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:08:27 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/13 14:27:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to push the first element of b to a and remove it from b
int    push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *pushed;
    
    if (!stack_b || !*stack_b)
        return (-1);
    pushed = dclst_insert_node_start(stack_a, (*stack_b)->data);
    if (!pushed)
        return (-1); // Attention a free
    dclst_remove_node(stack_b, *stack_b);
    return (0);
}

// Function to push the first element of a to b and remove it from a
int    push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *pushed;
    
    if (!stack_a || !*stack_a)
        return (-1);
    pushed = dclst_insert_node_start(stack_b, (*stack_a)->data);
    if (!pushed)
        return (-1); // Attention a free
    dclst_remove_node(stack_a, *stack_a);
    return (0);
}