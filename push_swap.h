/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:34 by nboer             #+#    #+#             */
/*   Updated: 2024/07/29 22:05:25 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include "/home/nboer/git/Libft/libft.h"
#include "/home/nick/42Berlin/push_swap/Libft/libft.h"

// int functie()
// {
// 	t_stack	stack;
// 	int		*i;
// 	int		*j;

// 	// i = malloc(sizeof(int));
// 	// j = malloc(sizeof(int));
// 	// *i = 1;
// 	// *j = 2;
// 	// stack.lst_first = ft_lstnew(i);
	
// 	ft_lstadd_front(&stack.lst_first, ft_lstnew(j));

// }

typedef struct s_stack
{
	t_list				*lst_first;
	int					min;
	int					max;
	int					size;
}	t_stack;

typedef struct s_move
{
	int					pos_a;
	int					pos_b;
	int					direction_a;
	int					direction_b;
	int					steps_a;
	int					steps_b;
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
int				is_sorted(t_list *stack);
int				get_index(t_list *stack_a, int num);
void			free_lst(t_list **lst);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
int				find_max(t_stack *stack);
int				find_min(t_stack *stack);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			ft_sort_3num(t_list *stack_a);
void			init_stack(t_stack *stack);

//void			sort_ab(t_list **stack_a, t_list **stack_b);

#endif
