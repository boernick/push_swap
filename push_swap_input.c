/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:46:35 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 18:32:49 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that checks if there are double numbers in the stack
// function that checks if there are 

void	input_single(char*	arg, t_list **stack_a)
{
	char	**str_arr;
	int	num;
	int	i;

	i = 0;
	str_arr = ft_split(arg, ' '); // don't forget to free later
	if (*str_arr == NULL) // Check if ft_split succeeded
		ft_error();
	while (str_arr[i])
		{
			num = atoi(str_arr[i]); // array of strings naar array of integers
			
			ft_lstadd_back(stack_a, newnode_int(num)); // PROBLEEM: ik moet een void pointer als input hebben, waar ik memory voor moet allocaten
			i++;
		}
}

void	input_multiple(char **arg, int argc, t_list **stack_a)
{
	int i;
	int	num;
	
	i = 1; //because the 0 index is the file location
	while (i < argc)
	{
		num = atoi(arg[i]);
		ft_lstadd_back(stack_a, newnode_int(num)); //<< to be fixed
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
