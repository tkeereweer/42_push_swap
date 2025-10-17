/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:27:42 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 11:58:13 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ret_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_set_index(t_list **head)
{
	t_list	*node;
	int		i;

	node = *head;
	i = 0;
	while (node != (void *) 0)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

int	is_sorted(t_list **head_a)
{
	t_list	*curr;
	int		prev;

	curr = *head_a;
	prev = -1;
	while (curr != (void *) 0)
	{
		if (prev != -1 && prev > curr->pos)
			return (0);
		prev = curr->pos;
		curr = curr->next;
	}
	return (1);
}
