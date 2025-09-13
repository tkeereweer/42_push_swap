/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:00:50 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/13 18:58:07 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_lstinit(int argc, char *argv[])
{
	t_list	**head;
	int		i;

	*head = ft_lstnew(&argv[1]);
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(head, ft_lstnew(&argv[i]));
		i++;
	}
}

void	ft_push(t_list **head_a, t_list **head_b, char stack)
{
	t_list	*tmp;
	t_list	*node;
	
	if (stack == 'a')
	{
		node = *head_b;
		tmp = node->next;
		ft_lstadd_front(head_a, *head_b);
		*head_b = tmp;
	}
	else if (stack == 'b')
	{
		node = *head_a;
		tmp = node->next;
		if (head_b == (void *) 0)
			*head_b = *head_a;
		else
			ft_lstadd_front(head_b, *head_a);
		*head_a = tmp;
	}
}

void	ft_swap(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*tmp;
	t_list	*node;

	node = *head_1;
	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	*head_1 = tmp;
	if (head_2 != (void *) 0)
	{
		node = *head_2;
		tmp = node->next;
		node->next = node->next->next;
		tmp->next = node;
		*head_2 = tmp;
	}
}

void	ft_rotate(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*node;

	node = *head_1;
	*head_1 = node->next;
	ft_lstadd_back(head_1, node);
	if (head_2 != (void *) 0)
	{
		node = *head_2;
		*head_2 = node->next;
		ft_lstadd_back(head_2, node);
	}
}

void	ft_revrotate(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*last_node;
	t_list	*node;

	last_node = ft_lstlast(*head_1);
	node = *head_1;
	ft_lstadd_front(head_1, last_node);
	while (node->next->next != (void *) 0)
		node = node->next;
	node->next = (void *) 0;
	if (head_2 != (void *) 0)
	{
		last_node = ft_lstlast(*head_2);
		node = *head_2;
		ft_lstadd_front(head_2, last_node);
		while (node->next->next != (void *) 0)
			node = node->next;
		node->next = (void *) 0;
	}
}
