/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:05:33 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:27:46 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort(t_stack *a, t_stack *b)
{
	t_move	cheapest;

	check_stacks(a, b);
	if ((a->size > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	if ((a->size > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	while ((a->size > 3) && (!is_sorted(a)))
	{
		find_cheapest(a, b, &cheapest);
		move_cheapest(a, b, &cheapest);
		push_top_a(a, b);
	}
	if (a->size == 3 && (!is_sorted(a)))
		ft_sort_3num(a);
	while (b->lst_first != NULL)
	{
		find_target_index_a(a, b, &cheapest);
		move_target_a(a, &cheapest);
		push_top_b(b, a);
	}
	min_first(a);
	if (ft_lstsize(a->lst_first) == 2 && (!is_sorted(a)))
		swap_top_a(a, 1);
}

void	min_first(t_stack *a)
{
	int	index_min;
	int	i;

	i = 0;
	index_min = find_index(a->lst_first, a->min);
	if (index_min < (a->size / 2))
	{
		while (i < index_min)
		{
			rotate_a(a, 1);
			i++;
		}
	}
	else
	{
		while (i < (a->size - index_min))
		{
			rev_rotate_a(a, 1);
			i++;
		}
	}
}

void	move_target_a(t_stack *a, t_move *cheapest)
{
	int	i;

	i = 0;
	if (cheapest->index_a <= (a->size / 2))
	{
		while (i < cheapest->index_a)
		{
			rotate_a(a, 1);
			i++;
		}
	}
	else
	{
		while (i < (a->size - cheapest->index_a))
		{
			rev_rotate_a(a, 1);
			i++;
		}
	}
}

void	find_target_index_a(t_stack *a, t_stack *b, t_move *cheapest)
{
	int		checknum;
	int		first_bigger;
	int		i;
	t_list	*temp;

	i = 0;
	checknum = *(int *)b->lst_first->content;
	first_bigger = INT_MAX;
	temp = a->lst_first;
	if (checknum < a->min || checknum > a->max)
		cheapest->index_a = find_index(a->lst_first, a->min);
	else
	{
		while (temp)
		{
			if (*(int *)temp->content > checknum && 
				*(int *)temp->content < first_bigger)
			{
				first_bigger = *(int *)temp->content;
				cheapest->index_a = i;
			}
			i++;
			temp = temp->next;
		}
	}
}
