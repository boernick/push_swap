/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:23:09 by nboer             #+#    #+#             */
/*   Updated: 2024/07/20 16:46:30 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

// IMPORTANT NOTE: TO BUILD; FIRST MAKE FCLEAN, THEN MAKE, THEN F5 TO DEBUG THE EXECUTABLE.

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
	t_list	*stack_b;
	int i;
	
	stack_a = NULL;
	stack_b = NULL;
	i = 1; //because the 0 index is the file location
	if (check_input(argc, argv))
	{
		while (i < argc)
			{
				ft_lstadd_back(&stack_a,  ft_lstnew(argv[i]));
				ft_lstadd_back(&stack_b, ft_lstnew("000 "));
				i++;
			}
		print_list(stack_a);
		print_list(stack_b);
		swap_top_both(&stack_a, &stack_b); // works in both directions!
		print_list(stack_a);
		print_list(stack_b);
	}	
	return (0);
}
