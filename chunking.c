/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/15 10:52:41 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_list	*ft_node_to_insert(int argc, t_list **head_a, int chunks, t_stacks *stacks, int i)
{
	t_list	*curr;
	t_cost	cheapest_cost;
	t_cost	curr_cost;

	curr = *head_a;
	cheapest_cost.cost = -1;
	while (curr != (void *) 0)
	{
		if (curr->pos < ((argc - 1) / chunks) * (i + 1))
			curr_cost.cost = ft_min(curr->index, stacks->len_a - curr->index);
		if (cheapest_cost.cost == -1 || curr_cost.cost < cheapest_cost.cost)
		{
			cheapest_cost.node = curr;
			cheapest_cost.cost = curr_cost.cost;
		}
		curr = curr->next;
	}
	return (cheapest_cost.node);
}

void	chunks_to_b(int argc, t_list **head_a, t_list **head_b, int chunks, t_stacks *stacks)
{
	int		i;
	int		j;
	t_list	*node_to_push;

	i = 0;
	while (i < chunks)
	{
		j = 0;
		while (j < (argc - 1) / chunks)
		{
			node_to_push = ft_node_to_insert(argc, head_a, chunks, stacks, i);
			while (*head_a != node_to_push)
			{
				if (node_to_push->index < stacks->len_a / 2)
					ft_rotate(head_a, (void *) 0, 'a');
				else
					ft_revrotate(head_a, (void *) 0, 'a');
			}
			ft_push(head_a, head_b, 'b', stacks);
			j++;
		}
		i++;
	}
	while (*head_a)
		ft_push(head_a, head_b, 'b', stacks);
}

void	push_largest_to_a(int argc, t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < argc - 1)
	{
		node = *head_b;
		while (node->pos != argc - 2 - i)
			node = node->next;
		if (node->index > (argc - 2 - i) / 2)
		{
			while (node->index != 0)
				ft_revrotate(head_b, (void *) 0, 'b');
		}
		else
			while (node->index != 0)
				ft_rotate(head_b, (void *) 0, 'b');
		ft_push(head_a, head_b, 'a', stacks);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list		*lst_a;
	t_list		*lst_b;
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	lst_a = ft_lstinit(argc, argv);
	lst_b = (void *) 0;
	stacks.len_a = argc - 1;
	stacks.len_b = 0;
	if (argc - 1 < 200)
		chunks_to_b(argc, &lst_a, &lst_b, stacks.len_a / 18, &stacks);
	else
		chunks_to_b(argc, &lst_a, &lst_b, stacks.len_a / 45, &stacks);
	push_largest_to_a(argc, &lst_a, &lst_b, &stacks);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
