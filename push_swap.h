/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:34 by nboer             #+#    #+#             */
/*   Updated: 2024/07/20 16:51:03 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
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

// void	get_user_input(int argc, char *argv[]);
int 			check_input(int argc, char *argv[]);
void			add_node_stack(t_stack_node **lst, char *num);
void			push_top_a(t_list **src, t_list **dst);
void			push_top_b(t_list **src, t_list **dst);
void			swap_top_a(t_list **lst);
void			swap_top_b(t_list **lst);
void			swap_top_both(t_list **lst_a, t_list **lst_b);


#endif
