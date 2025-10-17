/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:27:42 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 10:40:27 by mkeerewe         ###   ########.fr       */
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
