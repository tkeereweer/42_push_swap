/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:42:22 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/23 13:36:34 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*curr;

	if (lst == (void *) 0 || !f)
		return ;
	curr = lst;
	while (curr->next != (void *) 0)
	{
		f(curr->content);
		curr = curr->next;
	}
	f(curr->content);
}
