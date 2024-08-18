/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:51:42 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:03:15 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newnode_int(int value)
{
	t_list	*new_node;
	int		*num_p;

	num_p = malloc(sizeof(int));
	if (num_p == NULL)
		ft_error();
	*num_p = value;
	new_node = ft_lstnew(num_p);
	if (new_node == NULL)
		free(num_p);
	return (new_node);
}

void	free_stack(t_stack *a)
{
	t_list	*tmp_a;

	if (!a->lst_first)
		return ;
	while (a->lst_first)
	{
		tmp_a = a->lst_first->next;
		free(a->lst_first->content);
		free(a->lst_first);
		a->lst_first = tmp_a;
	}
	a->lst_first = NULL;
}

void	ft_error_free(t_stack *a)
{
	free_stack(a);
	ft_error();
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
