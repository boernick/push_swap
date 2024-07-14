/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:09 by nboer             #+#    #+#             */
/*   Updated: 2024/07/14 20:04:53 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	print_list(t_stack_node *lst)
{
	t_stack_node	*tmp;
	
	tmp = lst;
	while (tmp->next != NULL)
		printf("%s\n", tmp->num);
		tmp = tmp->next;
}

t_stack_node* add_node_stack(t_stack_node **lst, int num)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	// WHat if the list is still empty?
	if (!*lst)
		return (NULL);
	last_node = // TRAVERSE LIST FUNCTION
	new_node = malloc (sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	print_list(lst)

}

	int check_input(int argc, char *argv[])
	{
		if (argc < 2 || !(argv[1]))
		{
			printf("input error");
			return (0);
		}
		else
			printf("%c\n", argv[2][1]);
		return (1);
	}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	// t_stack_node	*stack_b;
	int i;
	
	i = 0;
	if (check_input(argc, argv))
	{
		while (i < argc - 1)
			{
				add_node_stack(&stack_a, argv[i]);
				i++;
			}
	}	
	return (0);
}
