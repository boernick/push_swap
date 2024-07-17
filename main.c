/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:09 by nboer             #+#    #+#             */
/*   Updated: 2024/07/17 20:01:39 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

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

int check_input(int argc, char *argv[])
{
	if (argc < 2 || !(argv[1]))
	{
		printf("input error");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	// t_stack_node	*stack_b;
	int i;
	
	stack_a = NULL;
	i = 1; //because the 0 index is the file location
	if (check_input(argc, argv))
	{
		while (i < argc)
			{
				ft_lstadd_back(&stack_a,  ft_lstnew(argv[i]));
				i++;
			}
		print_list(stack_a);
	}	
	return (0);
}
