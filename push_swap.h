/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:34 by nboer             #+#    #+#             */
/*   Updated: 2024/08/03 23:24:12 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "/home/nboer/git/Libft/libft.h"
// #include "/home/nick/42Berlin/push_swap/Libft/libft.h"

typedef struct s_stack
{
	t_list				*lst_first;
	int					min;
	int					max;
	int					size;
}	t_stack;

typedef struct s_move //overschrijven zodra er een goedkopere move is gevonden
{
	int					index_a; // de goedkoopste node om te pushen?
	int					index_b; // de node waarnaar toe te pushen
	int					direction_a; // richting om de goedkoopste node in A bovenaan de lijst te krijgen
	int					direction_b; // richting om de goedkoopste node in B bovenaan de lijst te krijgen
	int					steps_a; // aantal stappen A...
	int					steps_b; // aantal stappen B
	int					steps_total; // gezamenlijk ()
}	t_move;

int				check_input(int argc, char *argv[]);
void			input_single(char*	arg, t_stack *stack_a);
void			input_multiple(char **arg, int argc, t_stack *stack_a);
void			print_list(t_list *lst);
void			push_top_a(t_stack *stack_a, t_stack *stack_b);
void			push_top_b(t_stack *stack_b, t_stack *stack_a);
void			swap_top_a(t_stack *stack, int j);
void			swap_top_b(t_stack *stack, int j);
void			swap_top_both(t_stack *stack_a, t_stack *stack_b);
void			rotate_a(t_stack *stack, int j);
void			rotate_b(t_stack *stack, int j);
void			rotate_both(t_stack *stack_a, t_stack *stack_b);
void			rev_rotate_a(t_stack *stack, int j);
void			rev_rotate_b(t_stack *stack, int j);
void			rev_rotate_both(t_stack *stack_a, t_stack *stack_b);
void			ft_error(void);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*newnode_int(int value);
void			init_sort(t_stack *a, t_stack *b);
int				is_sorted(t_stack *stack);
int				get_index(t_stack *stack, int index);
void			free_lst(t_list **lst);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
int				find_max(t_stack *stack);
int				find_min(t_stack *stack);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			init_stack(t_stack *stack_a);
void			ft_sort_3num(t_stack *stack_a);
void			check_stack_a(t_stack *a, t_stack *b);
void			set_stack(t_stack *stack);
void			find_cheapest_way(t_move *current, t_stack *a, t_stack *b);
void			find_target(t_move *current, t_stack *a, t_stack *stack_b)

//void			sort_ab(t_list **stack_a, t_list **stack_b);

#endif
