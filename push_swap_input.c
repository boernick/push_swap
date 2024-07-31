/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:46:35 by nboer             #+#    #+#             */
/*   Updated: 2024/07/31 23:22:53 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that checks if there are double numbers in the stack --> this is after list creation
// function that checks if there are non-alphanumerical? --> this should be before list creation

void	init_stack(t_stack *stack)
{
	stack->lst_first = NULL;
	stack->min = 0;
	stack->max = 0;
	stack->size = 0;
}

void	input_single(char*	arg, t_stack *stack_a)
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
			num = atoi(str_arr[i]); // array of strings to array of integers
			ft_lstadd_back(&(stack_a->lst_first), newnode_int(num)); // check of het addfront moet zijn
			i++;
		}
}

void	input_multiple(char **arg, int argc, t_stack *stack_a)
{
	int i;
	int	num;
	
	i = 1; //because the 0 index is the file location
	while (i < argc)
	{
		num = ft_atoi(arg[i]);
		ft_lstadd_back(&(stack_a->lst_first), newnode_int(num)); //<< to be fixed
		i++;
	}
}

int	check_input(int argc, char *argv[]) // add check for alphanumerical
{
	if (argc < 2 || !(argv[1]))
	{
		ft_error();
		return (0);
	}
	return (1);
}
