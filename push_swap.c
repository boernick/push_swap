/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:21:34 by nboer             #+#    #+#             */
/*   Updated: 2024/08/07 19:50:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc > 1)
	{
		input_multiple(argv + 1, argc - 1, &stack_a);
		if (find_dup(&stack_a))
		{
			free_stack(&stack_a);
			free_stack(&stack_b);
			ft_error();
		}
		init_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
