/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:05:33 by nboer             #+#    #+#             */
/*   Updated: 2024/08/04 23:16:05 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check de header format

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
	while ((b->lst_first) && (!is_sorted(a)))
	{	
		find_target_index_a(a, b, &cheapest);
		move_target_a();
		push_top_b(a, b);
	}
	if (ft_lstsize(a->lst_first) == 2 && (!is_sorted(a)))
		swap_top_a(a, 1);
}
void	find_target_index_a(t_stack *a, t_stack *b, t_move *cheapest)
{
	int		checknum;
	int		first_bigger;
	int		i;
	t_list	*temp;

	i = 0;
	checknum = b->lst_first;
	first_bigger = INT_MAX;
	temp = a->lst_first;
	if (checknum < a->min || checknum > a->max)
		cheapest->index_a = find_index(a->lst_first, a->max);
	else
		while (temp)
		{
			if (*(int *)temp->content > checknum && *(int *)temp->content < first_bigger)
			{
				first_bigger = *(int *)temp->content;
				cheapest->index_a = i;
			}
			i++;
			temp = temp->next;
		}
}

void	move_cheapest(t_stack *a, t_stack *b, t_move *cheapest)
{
	if (cheapest->dir_a == 1 && cheapest->dir_b == 1)
		do_move_r_both(a, b, cheapest);
	else if (cheapest->dir_a == 0 && cheapest->dir_b == 0)
		do_move_rr_both(a, b, cheapest);
	else if (cheapest->dir_a == 1 && cheapest->dir_b == 0)
		do_move_ar_brr(a, b, cheapest);
	else if (cheapest->dir_a == 0 && cheapest->dir_b == 1)
		do_move_arr_br(a, b, cheapest);
	else
		ft_error();
}
void	do_move_r_both(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;

	i = 0;
	while (i < ft_min(cheapest->steps_a, cheapest->steps_b))
	{
		rotate_both(a, b);
		i++;
	}
	while (i < ft_max(cheapest->steps_a, cheapest->steps_b))
	{
		if (cheapest->steps_a > cheapest->steps_b)
			rotate_a(a, 1);
		if (cheapest->steps_b > cheapest->steps_a)
			rotate_b(b, 1);
		i++;
	}
}

void	do_move_rr_both(t_stack *a, t_stack *b, t_move *cheapest)
{
		int	i;
		
		i = 0;
		while (i < ft_min(cheapest->steps_a, cheapest->steps_b))
		{
			rev_rotate_both(a, b);
			i++;
		}
		while (i < ft_max(cheapest->steps_a, cheapest->steps_b))
		{
			if (cheapest->steps_a > cheapest->steps_b)
				rev_rotate_a(a, 1);
			if (cheapest->steps_b > cheapest->steps_a)
				rev_rotate_b(b, 1);
			i++;
		}
}

void	do_move_ar_brr(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cheapest->steps_a)
	{
		rotate_a(a, 1);
		i++;
	}
	while (j < cheapest->steps_b)
	{
		rev_rotate_b(b, 1);
		j++;
	}
}
void	do_move_arr_br(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cheapest->steps_a)
	{
		rev_rotate_a(a, 1);
		i++;
	}
	while (j < cheapest->steps_b)
	{
		rotate_b(b, 1);
		j++;
	}
}

void	check_stacks(t_stack *a, t_stack *b)
{
	set_stack(a);
	set_stack(b);
}

void	set_stack(t_stack *stack)
{
	if (stack->lst_first) // deze toegevoegd omdat B eerst nog niet bestaan bij eerste keer aanroep
	{
		stack->size = ft_lstsize(stack->lst_first);
		stack->max = find_max(stack);
		stack->min = find_min(stack);
	}
}

int		find_target_index(t_move *current, t_stack *a, t_stack *stack_b)
{
	int		checknum;
	t_list	*temp;
	int		first_smaller;

	checknum = get_index(a, current->index_a);
	if (checknum < stack_b->min || checknum > stack_b->max)
		return (find_index(stack_b->lst_first, stack_b->max)); // VOLGENS MIJ KLOPT DEZE NIET
	first_smaller = INT_MIN; // this might be false!
	temp = stack_b->lst_first;
	while (temp)
		{
			if (*(int *)temp->content < checknum && *(int *)temp->content > first_smaller)
				first_smaller = *(int *)temp->content;
			temp = temp->next;
		}
		return (find_index(stack_b->lst_first, first_smaller));
}

void	find_cheapest(t_stack *a, t_stack *b, t_move *cheapest)
{
	t_move	current;
	t_list	*temp;

	cheapest->steps_total = INT_MAX; //CHANGE LATER TO LONG
	current.index_a = 0;
	temp = a->lst_first;
	while (temp) 
	{
		current.index_b = find_target_index(&current, a, b);
		find_cheapest_way(&current, a, b);
		if (current.steps_total < cheapest->steps_total)
			set_move(cheapest, &current); //kopieert alle waardes van current naar cheapest
		current.index_a++;
		temp = temp->next;
	}
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

void	find_cheapest_way(t_move *current, t_stack *a, t_stack *b)
{
	int cost;

	current->steps_total = INT_MAX;
	cost = ft_max(current->index_a, current->index_b); 
	if (cost <= current->steps_total)
		case_ar_br(current); // A up B up
	cost = ft_max((a->size - current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_arr_brr(current, a, b); // A down B down
	cost = ft_max((current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_ar_brr(current, b); // A up B down
	cost = ft_max((current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_arr_br(current, a); // A down B up
}
void	case_ar_br(t_move *current)
{
	current->dir_a = 1;
	current->dir_b = 1;
	current->steps_a = current->index_a;
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}
void	case_arr_brr(t_move *current, t_stack *a, t_stack *b)
{
	current->dir_a = 0;
	current->dir_b = 0;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}
void	case_ar_brr(t_move *current, t_stack *b)
{
	current->dir_a = 1;
	current->dir_b = 0;
	current->steps_a = current->index_a;
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

void	case_arr_br(t_move *current, t_stack *a)
{
	current->dir_a = 0;
	current->dir_b = 1;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
	}

int		ft_max(int a, int b)
{
	if (a > b)
		return a;
	else
		return (b);
}

int		is_sorted(t_stack *stack)
{
	t_list	*lst_tmp;
	int	i;

	if (!stack->lst_first)
		ft_error();
	lst_tmp = stack->lst_first;
	i = *(int*)lst_tmp->content;
	while (stack->lst_first)
	{
		if (i > *(int*)lst_tmp->content)
			return (0);
		i = *(int*)lst_tmp->content;
		lst_tmp = lst_tmp->next;
	}
	return (1);
}

int	get_index(t_stack *stack, int index) // get the value at a specific index
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

int	find_index(t_list *stack, int num) //find the index of a particular value
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
