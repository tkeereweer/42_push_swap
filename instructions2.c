/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:00:50 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 10:32:03 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **head_a, t_list **head_b, char stack, t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*node;

	if (stack == 'a')
	{
		node = *head_b;
		tmp = node->next;
		if (*head_a == (void *) 0)
		{
			*head_a = node;
			node->next = (void *) 0;
		}
		else
			ft_lstadd_front(head_a, node);
		*head_b = tmp;
		stacks->len_a += 1;
		stacks->len_b -= 1;
		ft_printf("%s", "pa\n");
	}
	else if (stack == 'b')
	{
		node = *head_a;
		tmp = node->next;
		if (*head_b == (void *) 0)
		{
			*head_b = node;
			node->next = (void *) 0;
		}
		else
			ft_lstadd_front(head_b, node);
		*head_a = tmp;
		stacks->len_a -= 1;
		stacks->len_b += 1;
		if (stacks->len_b == 0)
			stacks->min_b = (*head_b)->pos;
		else
			stacks->min_b = ft_min(stacks->min_b, (*head_b)->pos);
		ft_printf("%s", "pb\n");
	}
	ft_set_index(head_a);
	ft_set_index(head_b);
}

void	ft_swap(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*tmp;
	t_list	*node;

	node = *head_1;
	node->index = 1;
	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	tmp->index = 0;
	*head_1 = tmp;
	if (head_2 == (void *) 0)
		ft_printf("%s%c%c", "s", stack, '\n');
	if (head_2 != (void *) 0)
	{
		node = *head_2;
		node->index = 1;
		tmp = node->next;
		node->next = node->next->next;
		tmp->next = node;
		tmp->index = 0;
		*head_2 = tmp;
		ft_printf("%s", "ss\n");
	}
}

void	ft_rotate(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*node;

	node = *head_1;
	*head_1 = node->next;
	ft_lstadd_back(head_1, node);
	ft_set_index(head_1);
	if (head_2 == (void *) 0)
		ft_printf("%s%c%c", "r", stack, '\n');
	if (head_2 != (void *) 0)
	{
		node = *head_2;
		*head_2 = node->next;
		ft_lstadd_back(head_2, node);
		ft_set_index(head_2);
		ft_printf("%s", "rr\n");
	}
}

void	ft_revrotate(t_list **head_1, t_list **head_2, char stack)
{
	t_list	*last_node;
	t_list	*node;

	last_node = ft_lstlast(*head_1);
	node = *head_1;
	while (node->next != last_node)
		node = node->next;
	node->next = (void *) 0;
	ft_lstadd_front(head_1, last_node);
	ft_set_index(head_1);
	if (head_2 == (void *) 0)
		ft_printf("%s%c%c", "rr", stack, '\n');
	if (head_2 != (void *) 0)
	{
		last_node = ft_lstlast(*head_2);
		node = *head_2;
		while (node->next != last_node)
			node = node->next;
		node->next = (void *) 0;
		ft_lstadd_front(head_2, last_node);
		ft_set_index(head_2);
		ft_printf("%s", "rrr\n");
	}
}
