/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:21:34 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int argc, char *argv[])
{
	long	num;
	int		i;

	i = 0;
	while (i < argc)
	{
		if (check_str(argv[i]))
			return (0);
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	init_stack(t_stack *stack)
{
	stack->lst_first = NULL;
	stack->min = 0;
	stack->max = 0;
	stack->size = 0;
}

void	check_stacks(t_stack *a, t_stack *b)
{
	set_stack(a);
	set_stack(b);
}

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
