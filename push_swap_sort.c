/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:31:10 by nboer             #+#    #+#             */
/*   Updated: 2024/07/24 19:56:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Push two numbers to stack B
void	init_sort(t_list **stack_a, t_list **stack_b)
{
	// if ((ft_lstsize(*stack_a) > 3) && (!is_sorted(*stack_a)))
	// 	push_top_a(stack_a, stack_b);
	// if ((ft_lstsize(*stack_a) > 3) && (!is_sorted(*stack_a)))
	// 	push_top_a(stack_a, stack_b);
	// if ((ft_lstsize(*stack_a) > 3) && (!is_sorted(*stack_a)))
	//  	sort_abtill3(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		printf("sort that shit");
		// functie die 3 getallen sorteerd van klein naar groot
	// Nu A nog 3 waardes heeft en deze gesorteerd zijn van klein naar groot, B naar A pushen
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
// 	int case_ar_br; // A up B up
// 		case_ar_br = ft_max(get_index(a), get_index(b));
// 	int case_arr_brr; // A down b down
// 		case_arr_brr = ft_max(ft_lstsize(a)-get_index(NUM_A))
// 	int	case_ar_brr; // A up B down
// 	int case_arr_br; // A down B up

// 	// CALCULATE ROTATING COST
// 	while (a)
		
// 		if (*(int*)a->content < find_max(a))
		
// }

// void	sort_ba(t_list **stack_a, t_list **stack_b)
// {
// 	//find_cheapest()
// 		// if the first number needs 0 actions -> stop finding cheapest and immediate push the number
// 		// if the index of the checked number < (list length / 2)
// }
// //calculate push cost per number
// find_cheapest(t_list **a)
// {
// 	if index_checked_number > (ft_lstsize(a) / 2);
// )		
// 	// I need: index cheapest
// 	// I need: index 
// }

// WHAT IS THE RIGHT SPOT?
	// If the number you push from STACK_A to STACK_B is going to be the new biggest or the smallest number, you should place it just above the old biggest number in the STACK_B.
	// if (push_a > stack_bMAX || push_a < stack_bMIN)
	// 	PLACE ABOVE stack_bMAX --> TARGET NUMBER = b_MAX
	// 	push_a = stack_bMAX 

int		is_sorted(t_list *stack)
{
	int	i;
	if (!stack)
		ft_error();
	i = *(int*)stack->content;
	while (stack)
	{
		if (i > *(int*)stack->content)
			return (0);
		i = *(int*)stack->content;
		stack = stack->next;
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
