/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:34 by nboer             #+#    #+#             */
/*   Updated: 2024/07/14 18:50:24 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "/home/nboer/git/ft_printf/ft_printf.h"
#include "/home/nboer/git/Libft/libft.h"

typedef struct s_stack_node
{
	int				num;
	struct s_stack_node *next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
	int				max;
	int				min;
}	t_stack_node;

// void	get_user_input(int argc, char *argv[]);
int 			check_input(int argc, char *argv[]);
t_stack_node*	add_node_stack(t_stack_node **lst, int num);


#endif
