/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:01:29 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	is_sorted(t_stack *stack)
{
	t_list	*lst_tmp;
	int		i;

	if (!stack->lst_first)
		ft_error();
	lst_tmp = stack->lst_first;
	i = *(int *)lst_tmp->content;
	while (lst_tmp)
	{
		if (i > *(int *)lst_tmp->content)
			return (0);
		i = *(int *)lst_tmp->content;
		lst_tmp = lst_tmp->next;
	}
	return (1);
}

int	get_index(t_stack *stack, int index)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack->lst_first;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	return (*(int *)temp->content);
}

int	find_index(t_list *stack, int num)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (num == *(int *)stack->content)
			return (i);
		i++;
		stack = stack->next;
	}
	ft_error();
	return (-1);
}
