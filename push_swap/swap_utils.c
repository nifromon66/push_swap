/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ouroboros.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:52:32 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/15 20:52:27 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_previous_pointers(t_stack *head)
{
    t_stack *current;
    current = head;
    if (!head)
        return ;
    while (current->next != head)
    {
        current->next->previous = current;
        current = current->next;
    }
    current->next->previous = current;
}
// Function to swap 2 adjacent nodes in the doubly circular linked list
void    swap_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    if (node1->next == node2)
    {
        node1->next = node2->next;
        node1->previous->next = node2;
        node2->next->previous = node1;
        node2->previous = node1->previous;
        node2->next = node1;
        node1->previous = node2;
    }
    else
    {
        node2->previous->next = node1;
        node1->next->previous = node2;
        node2->next = node1->next;
        node1->previous = node2->previous;
        node2->previous = node1;
        node1->next = node2;
    }
}
// Function to swap 2 non adjacent nodes in the doubly circular linked list
void    swap_non_adjacent_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    t_stack *temp_next;
    t_stack *temp_previous;
    temp_next = node1->next;
    temp_previous = node1->previous;
    node1->previous->next = node2;
    node1->next->previous = node2;
    node2->previous->next = node1;
    node2->next->previous = node1;
    node1->next = node2->next;
    node1->previous = node2->previous;
    node2->next = temp_next;
    node2->previous = temp_previous;
}
// Function to swap 2 nodes in the doubly circular linked list
int swap_nodes(t_stack **head, t_stack *node1, t_stack *node2)
{
    if (!head || !*head || !node1 || !node2 || (node1 == node2))
        return (-1);
    if (*head == node1)
        *head = node2;
    else if (*head == node2)
        *head = node1;
    if (node1->next == node2 && node2->next == node1)
    {
        node1->previous->next = node2;
        node2->next->previous = node1;
        node1->next = node2->next;
        node1->previous = node2;
        node2->next = node1;
        node2->previous = node1->previous;
    }
    else if (node1->next == node2 || node2->next == node1)
        swap_adjacent_nodes(head, node1, node2);
    else
        swap_non_adjacent_nodes(head, node1, node2);
    update_previous_pointers(*head);
    return (0);
}