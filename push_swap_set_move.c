/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:53:49 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(t_stack *stack)
{
	if (stack->lst_first)
	{
		stack->size = ft_lstsize(stack->lst_first);
		stack->max = find_max(stack);
		stack->min = find_min(stack);
	}
}

int	find_targetindex(t_move *current, t_stack *a, t_stack *stack_b)
{
	int		checknum;
	t_list	*temp;
	int		first_smaller;

	checknum = get_index(a, current->index_a);
	if (checknum < stack_b->min || checknum > stack_b->max)
		return (find_index(stack_b->lst_first, stack_b->max));
	first_smaller = INT_MIN;
	temp = stack_b->lst_first;
	while (temp)
	{
		if (*(int *)temp->content < checknum && 
			*(int *)temp->content > first_smaller)
			first_smaller = *(int *)temp->content;
		temp = temp->next;
	}
	return (find_index(stack_b->lst_first, first_smaller));
}

void	find_cheapest(t_stack *a, t_stack *b, t_move *cheapest)
{
	t_move	current;
	t_list	*temp;

	cheapest->steps_total = INT_MAX;
	current.index_a = 0;
	temp = a->lst_first;
	while (temp) 
	{
		current.index_b = find_targetindex(&current, a, b);
		find_cheapest_way(&current, a, b);
		if (current.steps_total < cheapest->steps_total)
			set_move(cheapest, &current);
		current.index_a++;
		temp = temp->next;
	}
}

void	find_cheapest_way(t_move *current, t_stack *a, t_stack *b)
{
	int	cost;

	current->steps_total = INT_MAX;
	cost = ft_max(current->index_a, current->index_b); 
	if (cost <= current->steps_total)
		case_ar_br(current);
	cost = ft_max((a->size - current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_arr_brr(current, a, b);
	cost = ft_max((current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_ar_brr(current, b);
	cost = ft_max((current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_arr_br(current, a);
}

void	set_move(t_move *cheapest, t_move *current)
{
	cheapest->index_a = current->index_a;
	cheapest->index_b = current->index_b;
	cheapest->steps_a = current->steps_a;
	cheapest->steps_b = current->steps_b;
	cheapest->dir_a = current->dir_a;
	cheapest->dir_b = current->dir_b;
	cheapest->steps_total = current->steps_total;
}
