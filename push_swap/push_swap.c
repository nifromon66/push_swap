/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:20:05 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/19 09:42:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_stack *stack_a;

    stack_a = NULL;
    if (argc < 2)
        return (0);
    if (check_input(argc, argv) == -1)
        return (write(2, "Error\n", 6), 2);
    if (argc < 3)
    {
        if (is_int(ft_atoi_long(argv[1])) == -1)
            return (write(2, "Error\n", 6), 2);
        return (0);
    }
    stack_a = dclst_load(argc, argv);
    if (stack_a == NULL)
        return (write(2, "Error\n", 6), 2);
    return (0);
}

t_stack *dclst_load(int argc, char **argv)
{
    t_stack *head;
    t_stack *new;
    long    data;
    int     i;

    head = NULL;
    i = 1;
    while (i < argc)
    {
        data = ft_atoi_long(argv[i]);
        if (is_int(data) == -1 || check_double((int) data, head) == -1)
            return (dclst_clear(&head), NULL);
        new = dclst_insert_node_end(&head, (int) data);
        if (!new)
            return (dclst_clear(&head), NULL);
        i++;
    }
    return (head);
}

// Function to print the list
void dclst_print(t_stack *head)
{
    t_stack *current;
    
    if (!head)
        return ;
    current = head;
    printf("%d\n", current->data);
    current = current->next;
    while (current != head)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}