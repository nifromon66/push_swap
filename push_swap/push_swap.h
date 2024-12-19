/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:34:17 by nifromon          #+#    #+#             */
/*   Updated: 2024/12/19 09:44:12 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct      s_stack
{
    int             data;
    struct s_stack *next;
    struct s_stack *previous;
}                   t_stack;

// Function for the error manager.
int     check_input(int argc, char **array);
int     check_double(int data, t_stack *head);
int	    ft_isdigit(int c);
long	ft_atoi_long(const char *nptr);
int     is_int(long n);

// Function to manipulate Ouroboros
t_stack *dclst_load(int argc, char **argv);
t_stack *dclst_create_node(int data);
t_stack *dclst_insert_node_end(t_stack **head, int data);
t_stack *dclst_insert_node_start(t_stack **head, int data);
void    dclst_remove_node(t_stack **head, t_stack *node);
void    dclst_clear(t_stack **head);

// Function to execute the instructions
    // Function to swap
void   swap_non_adjacent_nodes(t_stack *node1, t_stack *node2);
void   swap_adjacent_nodes(t_stack *node1, t_stack *node2);
int    swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
int    swap_a(t_stack **stack_a);
int    swap_b(t_stack **stack_b);
int    swap_ab(t_stack **stack_a, t_stack **stack_b);
void   update_previous_pointers(t_stack *head);
    // Function to push
int    push_a(t_stack **stack_a, t_stack **stack_b);
int    push_b(t_stack **stack_a, t_stack **stack_b);
    // Function to rotate
int    rotate_a(t_stack **stack_a);
int    rotate_b(t_stack **stack_b);
int    rotate_ab(t_stack **stack_a, t_stack **stack_b);
    // Function to reverse rotate
int    reverse_rotate_a(t_stack **stack_a);
int    reverse_rotate_b(t_stack **stack_b);
int    reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

void    dclst_print(t_stack *head);

#endif