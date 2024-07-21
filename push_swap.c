/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:09 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 16:02:03 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IMPORTANT NOTE: BEFORE SUBMITTING, REMOVE THE -g (FOR DEBUGGING) FROM THE MAKEFILE

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	// t_list	*stack_b;
	int i;

	stack_a = NULL;
	// stack_b = NULL;
	i = 1; //because the 0 index is the file location
	if (check_input(argc, argv))
	{
		if (argc == 2) //IF 1 argument,deel de string op in een array van korte strings 
		{
			input_single(argv[1], stack_a);
		}
		if (argc > 2)
			{
				while (i < argc)
					{
						ft_lstadd_back(&stack_a,  ft_lstnew(argv[i]));
						i++;
					}
			}
			print_list(stack_a);
	}	
	return (0);
}
