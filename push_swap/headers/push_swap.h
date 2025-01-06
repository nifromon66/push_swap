/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:39:24 by nifromon          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:57 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include "../libft/headers/libft_H/libft.h"

// Structure for Ouroboros
typedef struct s_stack
{
	int				data;
	int				index;
	int				rr_cost;
	int				better_up;
	int				sort_cost;
    struct s_stack	*next;
	struct s_stack	*previous;
    struct s_stack	*target;
}					t_stack;

// SRC DIRECTORY
// src/big_bang_theory.c
// load the stack, free everything
t_stack	*big_bang(char **args);
void	big_crunch(t_stack **a, t_stack **b, char **args, int argc);
// src/swap_functions.c
// swap the first two elements of stack a, stack b, or both
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
// src/push_functions.c
// push the first element of stack b to stack a,
// or the first element of stack a to stack b
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
// src/rotate_functions.c
// rotate the stack a, stack b, or both
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
// src/reverse_rotate_functions.c
// reverse rotate the stack a, stack b, or both
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// src/sort.c
// sort the stack a
void	put_lowest_to_top(t_stack **a);
void	push_node_to_a(t_stack **a, t_stack **b, t_stack *node);
t_stack	*find_cheapest_node(t_stack *b);
void	sort_from_b_to_a(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
// src/variable_initializers.c
// initialize the variables (needed for sorting) of all the nodes
void	initialize_variables_in_b(t_stack *a, t_stack *b);
void	initialize_variables_in_a(t_stack *a);
int		calculate_sort_cost(t_stack *node);
t_stack	*find_target(t_stack *a, int data);
// src/sort_utils.c
// check if the first len nodes of stack are sorted or reverse sorted
// and sort tiny stacks
int		is_sorted(t_stack *stack, int len);
int		is_reverse_sorted(t_stack *stack, int len);
void	sort_2a(t_stack **a);
void	sort_2b(t_stack **b);
void	sort_3(t_stack **a);

// UTILS DIRECTORY
// utils/Ouroboros1.c utils/Ouroboros2.c utils/Ouroboros3.c utils/Ouroboros4.c
// functions to manipulate doubly circular linked lists
t_stack	*Ouroboros_create_node(int data);
t_stack	*Ouroboros_insert_node_end(t_stack **head, int data);
t_stack	*Ouroboros_insert_node_start(t_stack **head, int data);
void	Ouroboros_remove_node(t_stack **head, t_stack *node);
void	Ouroboros_clear(t_stack **head);
void	Ouroboros_print(t_stack *head);
t_stack	*Ouroboros_find_min(t_stack *head);
t_stack	*Ouroboros_find_max(t_stack *head);
int		Ouroboros_find_node_pos(t_stack *head, t_stack *node);
t_stack	*Ouroboros_find_node_with_pos(t_stack *head, int pos);
int		Ouroboros_count_nodes(t_stack *head);
int		Ouroboros_swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
void	Ouroboros_move_node(t_stack **origin, t_stack **destination, t_stack *node);
t_stack	*Ouroboros_find_next_higher(t_stack *head, t_stack *node);
// src/error_manager.c
// check if the input is valid, if it is an int, and if it has a double
int		check_input(char **args);
int		is_int(long n);
int		has_double(t_stack *head, int data);
// utils/ft_atoi_long.c
// convert a string to a long
long	ft_atoi_long(const char *nptr);

// BONUS DIRECTORY
// bonus/checker.c
// check if the instructions are valid and
// if the stack is sorted after executing the instructions
int		instruction_4(t_stack **a, t_stack **b, char *line);
int		instruction_3(t_stack **a, t_stack **b, char *line);
int		instruction(t_stack **a, t_stack **b, char *line);
int		checker(t_stack **a, t_stack **b);
// bonus/push_silent.c
// push the first element of one stack to another
// without printing anything
void	silent_pa(t_stack **a, t_stack **b);
void	silent_pb(t_stack **a, t_stack **b);
// bonus/reverse_rotate_silent.c
// reverse rotate the stack a, stack b, or both
// without printing anything
void	silent_rra(t_stack **a);
void	silent_rrb(t_stack **b);
void	silent_rrr(t_stack **a, t_stack **b);
// bonus/rotate_silent.c
// rotate the stack a, stack b, or both
// without printing anything
void	silent_ra(t_stack **a);
void	silent_rb(t_stack **b);
void	silent_rr(t_stack **a, t_stack **b);
// bonus/swap_silent.c
// swap the first two elements of stack a, stack b, or both
// without printing anything
void	silent_sa(t_stack **a);
void	silent_sb(t_stack **b);
void	silent_ss(t_stack **a, t_stack **b);

#endif
