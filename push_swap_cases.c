/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:33:52 by nboer             #+#    #+#             */
/*   Updated: 2024/08/18 17:02:41 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ar_br(t_move *current)
{
	current->dir_a = 1;
	current->dir_b = 1;
	current->steps_a = current->index_a;
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

void	case_arr_brr(t_move *current, t_stack *a, t_stack *b)
{
	current->dir_a = 0;
	current->dir_b = 0;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

void	case_ar_brr(t_move *current, t_stack *b)
{
	current->dir_a = 1;
	current->dir_b = 0;
	current->steps_a = current->index_a;
	current->steps_b = (b->size - current->index_b);
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}

void	case_arr_br(t_move *current, t_stack *a)
{
	current->dir_a = 0;
	current->dir_b = 1;
	current->steps_a = (a->size - current->index_a);
	current->steps_b = current->index_b;
	current->steps_total = ft_max(current->steps_a, current->steps_b);
}
