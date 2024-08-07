/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:46:35 by nboer             #+#    #+#             */
/*   Updated: 2024/08/07 19:17:27 by nboer            ###   ########.fr       */
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

int	check_str(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	ft_atol(const char *nptr)
{
	int		i;
	int		is_neg;
	long	num;

	i = 0;
	is_neg = 1;
	num = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = 10 * num + nptr[i] - '0';
		i++;
	}
	return (is_neg * num);
}

int	find_dup(t_stack *a)
{
	t_list	*tmp;
	t_list	*tmp_dup;
	int		check_num;

	if (!a || !a->lst_first)
		ft_error();
	tmp = a->lst_first;
	while (tmp)
	{
		check_num = *(int *)tmp->content;
		tmp_dup = tmp->next;
		while (tmp_dup)
		{
			if (check_num == *(int *)tmp_dup->content)
				ft_error_free(a);
			tmp_dup = tmp_dup->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	init_stack(t_stack *stack)
{
	stack->lst_first = NULL;
	stack->min = 0;
	stack->max = 0;
	stack->size = 0;
}

int	arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	input_multiple(char **arg, int argc, t_stack *stack_a)
{
	int	i;
	int	num;
	int	count;

	i = 0;
	if (argc == 1)
	{
		arg = ft_split(arg[0], ' ');
		count = arrlen(arg);
	}
	else 
		count = argc;
	if (arg == NULL || !check_input(count, arg))
	{
		if (argc == 1)
			ft_free_arr(arg);
		ft_error();
	}
	while (i < count)
	{
		num = ft_atoi(arg[i++]);
		ft_lstadd_back(&(stack_a->lst_first), newnode_int(num));
	}
	if (argc == 1)
		ft_free_arr(arg);
}
