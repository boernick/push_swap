/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:20:47 by nboer             #+#    #+#             */
/*   Updated: 2024/08/07 20:05:42 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	if (stack_a->lst_first == NULL || stack_a == NULL || stack_b == NULL)
		return ;
	tmp = stack_a->lst_first;
	stack_a->lst_first = stack_a->lst_first->next;
	if (!stack_b->lst_first)
	{
		stack_b->lst_first = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = stack_b->lst_first;
		stack_b->lst_first = tmp;
	}
	stack_a->size--;
	stack_b->size++;
	check_stacks(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_top_b(t_stack *stack_b, t_stack *stack_a)
{
	t_list	*tmp;

	if (stack_b->lst_first == NULL || stack_a == NULL)
		return ;
	tmp = stack_b->lst_first;
	stack_b->lst_first = stack_b->lst_first->next;
	tmp->next = stack_a->lst_first;
	stack_a->lst_first = tmp;
	stack_b->size--;
	stack_a->size++;
	check_stacks(stack_a, stack_b);
	write(1, "pa\n", 3);
}

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

void	swap_top_b(t_stack *stack, int j)
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
		write(1, "sb\n", 3);
}

void	swap_top_both(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->lst_first) == NULL || (stack_b->lst_first) == NULL)
		return ;
	swap_top_a(stack_a, 0);
	swap_top_b(stack_b, 0);
	write(1, "SS\n", 3);
}

void	rotate_a(t_stack *stack, int j)
{
	t_list	*first;
	t_list	*last;

	first = stack->lst_first;
	last = stack->lst_first;
	while (last->next != NULL)
		last = last->next;
	stack->lst_first = first->next;
	last->next = first;
	first->next = NULL;
	if (j == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack, int j)
{
	t_list	*first;
	t_list	*last;

	first = stack->lst_first;
	last = stack->lst_first;
	while (last->next != NULL)
		last = last->next;
	stack->lst_first = first->next;
	last->next = first;
	first->next = NULL;
	if (j == 1)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *lst_a, t_stack *lst_b)
{
	rotate_a(lst_a, 0);
	rotate_b(lst_b, 0);
	write(1, "rr\n", 3);
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
