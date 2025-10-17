/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:33:25 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 10:18:00 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pos(int argc, t_list **head)
{
	t_list	*node;
	t_list	*min_node;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		node = *head;
		min_node = (void *) 0;
		while (node)
		{
			if (node->pos == -1
				&& (!min_node || node->content < min_node->content))
				min_node = node;
			node = node->next;
		}
		if (min_node)
			min_node->pos = i;
		i++;
	}
}

t_list	*ft_lstinit(int argc, char *argv[])
{
	t_list	*lst;
	int		i;

	lst = ft_lstnew(ft_atoi(argv[1]), 0);
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	get_pos(argc, &lst);
	return (lst);
}
