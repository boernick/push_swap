/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:20:47 by nboer             #+#    #+#             */
/*   Updated: 2024/07/20 16:45:05 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2 lists A B are already made; next function needs to take 2 lists as input, switch the first two

#include "push_swap.h"

void	push_top(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (src == NULL || dst == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	write(1, "PA\n", 3);

}

void	swap_top_a(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	write(1, "SA\n", 3);
}

void	swap_top_b(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	write(1, "SB\n", 3);
}

void	swap_top_both(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a) == NULL || (*lst_b) == NULL)
		return ;
	swap_top_a(lst_a);
	swap_top_b(lst_b);
}

