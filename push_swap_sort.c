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
	if ((ft_lstsize((a->lst_first)) > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	if ((ft_lstsize(a->lst_first) > 3) && (!is_sorted(a)))
		push_top_a(a, b);
	if ((ft_lstsize(a->lst_first) > 3) && (!is_sorted(a)))
	 	// sort_abtill3(a, b);
		return;
	if (ft_lstsize(a->lst_first) == 2 && (!is_sorted(a)))
		swap_top_a(a, 1);
	if (ft_lstsize(a->lst_first) == 3 && (!is_sorted(a)))
	{
		ft_sort_3num(a);
		print_list(a->lst_first);
	}
	// and then push all numbers from B to A.
}
// void	sort_ab_till3(t_list **stack_a, t_list **stack_b)
// {
// 	// find_cheapest()
// 	if (checked_number < MIN_B || checked_number > MAX_B)
// 		targetnumber = MAX_B;
	
	
// 	printf("start sorting");
// }
// void	find_cheapest(t_list *a, t_list *b)
// {

// //VOOR ALLE NUMMERS IN A, CHECK HET VOLGENDE:
// 	//ROTATION COST	
// 		// TERWIJL A && B_TARGET ARE BOTH NOT INDEX(0)
// 		int case_ar_br; // A up B up
// 			case_ar_br = ft_max(get_index(a), get_index(b));
// 		int case_arr_brr; // A down b down
// 			case_arr_brr = ft_max(ft_lstsize(a)-get_index(numcheck_a))
// 		int	case_ar_brr; // A up B down
// 		int case_arr_br; // A down B up

// 		// if one of the options is 0, then go for this method. (it cannot be quicker)

// 		// CALCULATE ROTATING COST
		
// }

// void	sort_ba(t_list **stack_a, t_list **stack_b)
// {
// 	//find_cheapest()
// 		// if the first number needs 0 actions -> stop finding cheapest and immediate push the number
// 		// if the index of the checked number < (list length / 2)
// }
// 	// I need: index cheapest
// 	// I need: index 
// }

// WHAT IS THE RIGHT SPOT?
	// If the number you push from STACK_A to STACK_B is going to be the new biggest or the smallest number, you should place it just above the old biggest number in the STACK_B.
	// if (push_a > stack_bMAX || push_a < stack_bMIN)
	// 	PLACE ABOVE stack_bMAX --> TARGET NUMBER = b_MAX
	// 	push_a = stack_bMAX 

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

int	get_index(t_list *stack_a, int num)
{
	int		i;
	
	i = 0;
	while (stack_a)
	{
		if (num == *(int *)stack_a->content)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	ft_error();
	return (-1);
}
