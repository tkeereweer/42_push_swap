/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 09:54:38 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_chunk_lim(t_stacks *stacks, int i, int argc)
{
	int	chunk_size = (argc - 1) / stacks->chunks;
	stacks->lower = chunk_size * i;
	stacks->upper = chunk_size * (i + 1) - 1;
	if (i == stacks->chunks - 1)
		stacks->upper = argc - 2;
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_list	*ft_node_to_insert(t_list **head_a, t_stacks *stacks)
{
	t_list	*curr;
	t_list	*cheapest_node;
	int		cost;

	curr = *head_a;
	cost = -1;
	while (curr != (void *) 0)
	{
		if (curr->pos >= stacks->lower && curr->pos <= stacks->upper)
		{
			if (cost == -1 || ft_min(curr->index, stacks->len_a - curr->index) < cost)
			{
				cost = ft_min(curr->index, stacks->len_a - curr->index);
				cheapest_node = curr;
			}
		}
		curr = curr->next;
	}
	return (cheapest_node);
}

int	node_in_chunk(t_list **head_a, t_stacks *stacks)
{
	t_list *curr;

	curr = *head_a;
	while (curr != (void *) 0)
	{
		if (curr->pos >= stacks->lower && curr->pos <= stacks->upper)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	chunks_to_b(t_list **head_a, t_list **head_b, t_stacks *stacks, int argc)
{
	int		i;
	t_list	*node_to_insert;

	i = 0;
	while (i < stacks->chunks)
	{
		get_chunk_lim(stacks, i, argc);
		while (node_in_chunk(head_a, stacks) == 1)
		{
			node_to_insert = ft_node_to_insert(head_a, stacks);
			if (!node_to_insert)
				break ;
			while (*head_a != node_to_insert)
			{
				if (node_to_insert->index < stacks->len_a / 2)
					ft_rotate(head_a, (void *) 0, 'a');
				else
					ft_revrotate(head_a, (void *) 0, 'a');
			}
			if (node_to_insert->pos < stacks->min_b)
			{
				ft_push(head_a, head_b, 'b', stacks);
				ft_rotate(head_b, (void *) 0, 'b');
			}
			else
				ft_push(head_a, head_b, 'b', stacks);
		}
		i++;
	}
	while (*head_a != (void *) 0)
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
	if (argc - 1 < 100)
		stacks.chunks = stacks.len_a / 3;
	else if (argc - 1 < 250)
		stacks.chunks = stacks.len_a / 18;
	else
		stacks.chunks = stacks.len_a / 45;
	chunks_to_b(&lst_a, &lst_b, &stacks, argc);
	push_largest_to_a(argc, &lst_a, &lst_b, &stacks);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
