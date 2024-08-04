/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:12:58 by nboer             #+#    #+#             */
/*   Updated: 2024/08/04 15:44:47 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3num(t_stack *a)
{
	if (*(int *)a->lst_first->content == find_max(a))
		rotate_a(a, 1);
	while (*(int *)(ft_lstlast(a->lst_first))->content != find_max(a))
		rev_rotate_a(a, 1);
	if(*(int *)a->lst_first->content != find_min(a))
		swap_top_a(a, 1);
}

int	find_max(t_stack *stack)
{
	int	max;
	t_list	*current;
	
	if (!(stack->lst_first) || !(stack))
		ft_error();
	current = stack->lst_first;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_list	*current;
		
	if (!(stack->lst_first) || !(stack))
		ft_error();
	current = stack->lst_first;
	min = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
}

void	free_lst(t_list **lst)
{
	t_list *tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next; // temporary is set to the upcoming node in the list
		free((*lst)->content); //free content in the current node
		free(*lst); // free the current node
		*lst = tmp; // assign head pointer to tmp which was the adress of the upcoming node, now repeat. 
	}
	*lst = NULL; // this is to prevent a dangling pointer - which hold the adress of previously freed memory.
}

t_list	*newnode_int(int value)
{
	t_list	*new_node;
	int		*num_p;

	num_p = malloc(sizeof(int));
	if (num_p == NULL)
		ft_error();
	*num_p = value;
	new_node = ft_lstnew(num_p);
	if (new_node == NULL)
		free(num_p);
	return (new_node);
}

void	print_list(t_list *lst)
{
	t_list	*tmp;
	
	if (!lst)
	{
		printf("%s\n", "empty");
		return ;
	}
	tmp = lst;
	while (tmp->next != NULL)
	{
		printf("%i ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("%i \n", *(int *)tmp->content);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
