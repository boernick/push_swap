/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:21:34 by nboer             #+#    #+#             */
/*   Updated: 2024/08/05 21:53:05 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IMPORTANT NOTE: BEFORE SUBMITTING, REMOVE THE -g (FOR DEBUGGING) FROM THE MAKEFILE
// 1. CHECK INPUTS FOR DOUBLE NUMBERS, WHITE SPACES, ETC
// 2. CHECK TO FREE UP ALL THE MEMORY DYNAMICALLY ALLOCATED
// 3. CHECK FOR INTEGER OVERFLOW.

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (check_input(argc, argv))
	{
		if (argc == 2) //IF 1 argument,deel de string op in een array van korte strings 
			input_single(argv[1], &stack_a);
		else if (argc > 2)
			input_multiple(argv, argc, &stack_a);
		printf("%s ", "Stack A before:");
		print_list((&stack_a)->lst_first);
		printf("%s ", "Stack B before:");
		print_list((&stack_b)->lst_first);
		init_sort(&stack_a, &stack_b);
		printf("%s ", "Stack A after:");
		print_list((&stack_a)->lst_first);
		printf("%s ", "Stack B after:");
		print_list((&stack_b)->lst_first);
	}	
	return (0);
}
