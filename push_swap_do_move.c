/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_do_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:28:35 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:42 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move_r_both(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;

	i = 0;
	while (i < ft_min(cheapest->steps_a, cheapest->steps_b))
	{
		rotate_both(a, b);
		i++;
	}
	while (i < ft_max(cheapest->steps_a, cheapest->steps_b))
	{
		if (cheapest->steps_a > cheapest->steps_b)
			rotate_a(a, 1);
		if (cheapest->steps_b > cheapest->steps_a)
			rotate_b(b, 1);
		i++;
	}
}

void	do_move_rr_both(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;

	i = 0;
	while (i < ft_min(cheapest->steps_a, cheapest->steps_b))
	{
		rev_rotate_both(a, b);
		i++;
	}
	while (i < ft_max(cheapest->steps_a, cheapest->steps_b))
	{
		if (cheapest->steps_a > cheapest->steps_b)
			rev_rotate_a(a, 1);
		if (cheapest->steps_b > cheapest->steps_a)
			rev_rotate_b(b, 1);
		i++;
	}
}

void	do_move_ar_brr(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cheapest->steps_a)
	{
		rotate_a(a, 1);
		i++;
	}
	while (j < cheapest->steps_b)
	{
		rev_rotate_b(b, 1);
		j++;
	}
}

void	do_move_arr_br(t_stack *a, t_stack *b, t_move *cheapest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cheapest->steps_a)
	{
		rev_rotate_a(a, 1);
		i++;
	}
	while (j < cheapest->steps_b)
	{
		rotate_b(b, 1);
		j++;
	}
}

void	move_cheapest(t_stack *a, t_stack *b, t_move *cheapest)
{
	if (cheapest->dir_a == 1 && cheapest->dir_b == 1)
		do_move_r_both(a, b, cheapest);
	else if (cheapest->dir_a == 0 && cheapest->dir_b == 0)
		do_move_rr_both(a, b, cheapest);
	else if (cheapest->dir_a == 1 && cheapest->dir_b == 0)
		do_move_ar_brr(a, b, cheapest);
	else if (cheapest->dir_a == 0 && cheapest->dir_b == 1)
		do_move_arr_br(a, b, cheapest);
	else
	{
		free_stack(a);
		free_stack(b);
		ft_error();
	}
}
