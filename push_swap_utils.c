/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:12:58 by nboer             #+#    #+#             */
/*   Updated: 2024/08/07 19:56:16 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	ft_sort_3num(t_stack *a)
{
	if (*(int *)a->lst_first->content == find_max(a))
		rotate_a(a, 1);
	while (*(int *)(ft_lstlast(a->lst_first))->content != find_max(a))
		rev_rotate_a(a, 1);
	if (*(int *)a->lst_first->content != find_min(a))
		swap_top_a(a, 1);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_list	*current;

	if (!(stack->lst_first) || !(stack))
		ft_error();
	current = stack->lst_first;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_list	*current;

	if (!(stack->lst_first) || !(stack))
		ft_error();
	current = stack->lst_first;
	min = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
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
