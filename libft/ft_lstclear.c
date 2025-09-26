/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:42:22 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/25 15:25:23 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*next_node;

	if (lst == (void *) 0 || *lst == (void *) 0)
		return ;
	curr = *lst;
	while (curr->next != (void *) 0)
	{
		next_node = curr->next;
		ft_lstdelone(curr);
		curr = next_node;
	}
	ft_lstdelone(curr);
	*lst = (void *) 0;
}
