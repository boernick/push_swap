/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:38:10 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_a(t_stack *stack, int j)
{
	t_list	*first;
	t_list	*second;

	if ((stack->lst_first) == NULL || (stack->lst_first->next == NULL))
		return ;
	first = stack->lst_first;
	second = stack->lst_first->next;
	first->next = second->next;
	second->next = first;
	stack->lst_first = second;
	if (j == 1)
		write(1, "sa\n", 3);
}

void	rev_rotate_a(t_stack *stack, int j)
{
	t_list	*second_last;
	t_list	*last;

	if (stack->lst_first == NULL || stack == NULL || 
		stack->lst_first->next == NULL)
		return ;
	last = stack->lst_first;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->lst_first;
	stack->lst_first = last;
	if (j == 1)
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack *stack, int j)
{
	t_list	*second_last;
	t_list	*last;

	if (stack->lst_first == NULL || stack == NULL || 
		stack->lst_first->next == NULL)
		return ;
	last = stack->lst_first;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->lst_first;
	stack->lst_first = last;
	if (j == 1)
		write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate_a(stack_a, 0);
	rev_rotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
