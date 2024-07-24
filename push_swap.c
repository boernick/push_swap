/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:09 by nboer             #+#    #+#             */
/*   Updated: 2024/07/24 19:56:39 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IMPORTANT NOTE: BEFORE SUBMITTING, REMOVE THE -g (FOR DEBUGGING) FROM THE MAKEFILE

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (check_input(argc, argv))
	{
	
		if (argc == 2) //IF 1 argument,deel de string op in een array van korte strings 
			input_single(argv[1], &stack_a);
		else if (argc > 2)
			input_multiple(argv, argc, &stack_a);
		printf("%s ", "Stack A before:");
		print_list(stack_a);
		printf("%s ", "Stack B before:");
		print_list(stack_b);
		init_sort(&stack_a, &stack_b);
		
		printf("%s ", "Stack A after:");
		print_list(stack_a);
		printf("%s ", "Stack B after:");
		print_list(stack_b);
	}	
	return (0);
}
