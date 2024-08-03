/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:31:10 by nboer             #+#    #+#             */
/*   Updated: 2024/07/29 21:21:15 by nboer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check de header format

#include "push_swap.h"

void	init_sort(t_stack *a, t_stack *b)
{
	check_stacks(a, b);
	if ((a->size > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	if ((a->size > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	while ((a->size > 3) && (!is_sorted(a)))
		// move_ab(a, b);
	if (a->size == 3 && (!is_sorted(a)))
	{
		ft_sort_3num(a);
		print_list(a->lst_first);
	}
	// while ((b->lst_first) && (!is_sorted(a)))
		// init_b(a, b);
		// move_ba(a, b);
	if (ft_lstsize(a->lst_first) == 2 && (!is_sorted(a)))
		swap_top_a(a, 1);
}

void	check_stacks(t_stack *a, t_stack *b)
{
	set_stack(a);
	set_stack(b);
}

void	set_stack(t_stack *stack)
{
	stack->size = ft_lstsize(stack->lst_first);
	stack->max = find_max(stack);
	stack->min = find_min(stack);
}

void	find_target(t_move *current, t_stack *a, t_stack *stack_b)
{
		// if one of the options is 0, then go for this method. (it cannot be quicker)

// WHAT IS THE RIGHT SPOT?
// 	If the number you push from STACK_A to STACK_B is going to be the new biggest or the smallest number, you should place it just above the old biggest number in the STACK_B.
// 	if (push_a > stack_bMAX || push_a < stack_bMIN)
// 		PLACE ABOVE stack_bMAX --> TARGET NUMBER = b_MAX
// 		push_a = stack_bMAX 

	int	checked_num;

	checked_num = get_index(current->index_a);
	if (checked_num < stack_b->min || checked_num > stack_b->max) // or stack_a->max?
		return (stack_b->max);
	
	
	printf("start sorting");
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	t_move	cheapest;
	t_move	current;
	t_list	*temp;

	cheapest.steps_total = INT_MAX;
	current.index_a = 0;
	temp = a->lst_first;
	while (temp) //ga door alle A nummers heen om te kijken wat het goedkoopste nummer is
	{
		current.index_b = find_target(&current, b);
		find_cheapest_way(&current, a, b);
		if (current.steps_total < cheapest.steps_total)
			set_move(&cheapest, &current); //kopieert alle waardes van current naar cheapest
		current.index_a++;
		temp = temp->next;
	}
}
void	set_move(t_move *cheapest, t_move *current)
{
	cheapest->steps_a = current->steps_a;
	cheapest->steps_b = current->steps_b;
	cheapest->direction_a = current->direction_a;
	cheapest->direction_b = current->direction_b;
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
		case_ar_brr(current, a, b); // A up B down
	cost = ft_max((current->index_a), (b->size - current->index_b));
	if (cost < current->steps_total)
		case_arr_br(current, a, b); // A down B up
}
void	case_ar_br(t_move *current)
{
	current->direction_a = 1;
	current->direction_b = 1;
	current->steps_a = current->index_a;
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}
void	case_arr_brr(t_move *current, t_stack *a, t_stack *b)
{
	current->direction_a = 0;
	current->direction_b = 0;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}
void	case_ar_brr(t_move *current, t_stack *a, t_stack *b)
{
	current->direction_a = 1;
	current->direction_b = 0;
	current->steps_a = current->index_a;
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

void	case_arr_br(t_move *current, t_stack *a, t_stack *b)
{
	current->direction_a = 0;
	current->direction_b = 1;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return a;
	if (b < a)
		return b;
}

int		ft_max(int a, int b)
{
	if (a > b)
		return a;
	if (b > a)
		return b;
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

	temp = stack->lst_first;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content)
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
