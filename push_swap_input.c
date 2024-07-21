/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:46:35 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 16:35:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that changes every string in a list to a integer;

void	input_single(char*	arg, t_list *stack_a)
{
	char	**str_arr;
	int	num;
	int	i;

	i = 0;
	str_arr = ft_split(arg, ' '); //deze array in een variable opslaan
	while (str_arr[i])
		{
			num = atoi(str_arr[i]); // array of strings naar array of integers
			ft_lstadd_back(&stack_a, ft_lstnew((void *)num));
			i++;
		}
}

int	check_input(int argc, char *argv[])
{
	if (argc < 2 || !(argv[1]))
	{
		ft_error();
		return (0);
	}
	return (1);
}
