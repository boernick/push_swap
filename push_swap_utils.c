/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:12:58 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 20:04:14 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_list **lst) //redo self if time
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
