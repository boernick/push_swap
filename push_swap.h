/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:34 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 16:18:24 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/nboer/git/Libft/libft.h"

typedef struct s_stack_node
{
	//change later the num to INT
	char*			num;
	struct s_stack_node *next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

int 			check_input(int argc, char *argv[]);
void			input_single(char*	arg, t_list *stack_a);
void			print_list(t_list *lst);
void			add_node_stack(t_stack_node **lst, char *num);
void			push_top_a(t_list **src, t_list **dst);
void			push_top_b(t_list **src, t_list **dst);
void			swap_top_a(t_list **lst, int j);
void			swap_top_b(t_list **lst, int j);
void			swap_top_both(t_list **lst_a, t_list **lst_b);
void			rotate_a(t_list **lst, int j);
void			rotate_b(t_list **lst, int j);
void			rotate_both(t_list **lst_a, t_list **lst_b);
void			rev_rotate_a(t_list **lst, int j);
void			rev_rotate_b(t_list **lst, int j);
void			rev_rotate_both(t_list **lst_a, t_list **lst_b);
void			ft_error(void);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);



#endif
