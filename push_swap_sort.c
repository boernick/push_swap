/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:31:10 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 20:53:26 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Push two numbers to stack B
void	init_sort(t_list **stack_a, t_list **stack_b)
{
	push_top_a(stack_a, stack_b);
	push_top_a(stack_a, stack_b);
}
//2. Check how many operations it takes for every number in A, to put it in the right spot in B
	// What do i need for this? function to get the index of a value(number) in A, 

// for each in stack_a->how many operations:
	// first. to the top of stack A
	// second. above the right number of stack b
// then check 
// 
int	get_index(t_list *stack_a, int num)
{
	int		i;
	
	i = 0;
	while (stack_a)
	{
		if (num == stack_a->content)
			return (i);
		i++;
		stack_a = stack_a->next;
	}
	ft_error();
	return (-1);
}
