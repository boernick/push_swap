/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:20:47 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 13:29:28 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_a(t_list **src, t_list **dst) //push top a to b
{
	t_list	*tmp;

	if (*src == NULL || src == NULL || dst == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	write(1, "PA\n", 3);
}

void	push_top_b(t_list **src, t_list **dst) //push top b to a
{
	t_list	*tmp;

	if (*src == NULL || src == NULL || dst == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	write(1, "PB\n", 3);
}

void	swap_top_a(t_list **lst, int j) //swap first A node with second A node 
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
	if (j == 1)
		write(1, "SA\n", 3);
}

void	swap_top_b(t_list **lst, int j) //swap first B node with second B node 
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
	if (j == 1)
		write(1, "SB\n", 3);
}

void	swap_top_both(t_list **lst_a, t_list **lst_b) // Swap both first nodes of A&B with the second nodes of both A&B
{
	if ((*lst_a) == NULL || (*lst_b) == NULL)
		return ;
	swap_top_a(lst_a, 0);
	swap_top_b(lst_b, 0);
	write(1, "SS\n", 3);

}

void	rotate_a(t_list **lst, int j) //The first A element becomes the last one.
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = first->next;
	last->next = first;
	first->next = NULL;
	if (j == 1)
		write(1, "RA\n", 3);
}

void	rotate_b(t_list **lst, int j) //The first B element becomes the last one.
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = first->next;
	last->next = first;
	first->next = NULL;
	if (j == 1)
		write(1, "RB\n", 3);
}

void	rotate_both(t_list **lst_a, t_list **lst_b) //THe first A becomes last A, first B becomes last B
{
	rotate_a(lst_a, 0);
	rotate_b(lst_b, 0);
	write(1, "RR\n", 3);
}
void	rev_rotate_a(t_list **lst, int j) //The last A element becomes the first one.
{
	t_list	*second_last;
	t_list	*last;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return;
	last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if (j == 1)
		write(1, "RRA\n", 4);
}

void	rev_rotate_b(t_list **lst, int j) //The last B element becomes the first one.
{
	t_list	*second_last;
	t_list	*last;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return;
	last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if (j == 1)
		write(1, "RRB\n", 4);
}

void	rev_rotate_both(t_list **lst_a, t_list **lst_b) //The last A&B elements become the first ones.
{
	rev_rotate_a(lst_a, 0);
	rev_rotate_b(lst_b, 0);
	write(1, "RRR\n", 4);
}
