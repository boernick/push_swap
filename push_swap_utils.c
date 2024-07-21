/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:12:58 by nboer             #+#    #+#             */
/*   Updated: 2024/07/21 14:31:36 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// build void ft_free(t_list *lst)

void	print_list(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp->next != NULL)
	{
		printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("%s \n", (char *)tmp->content);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
