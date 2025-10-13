/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_based_insertion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:39:39 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/09 16:13:20 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

t_list	*find_closest(t_list **head_b, t_list *node)
{
	t_list	*curr;
	t_list	*closest;

	curr = *head_b;
	closest = (void *) 0;
	while (curr != (void *) 0)
	{
		if (closest == (void *) 0
			|| (closest->pos > node->pos && curr->pos < closest->pos)
			|| (curr->pos < node->pos && curr->pos > closest->pos))
			closest = curr;
		curr = curr->next;
	}
	if (closest != (void *) 0 && closest->pos > node->pos)
	{
		curr = *head_b;
		while (curr != (void *) 0)
		{
			if (curr->pos > closest->pos)
				closest = curr;
			curr = curr->next;
		}
	}
	return (closest);
}

int	compute_cost(t_list **head_b, t_list *node, t_stacks *stacks)
{
	t_list	*curr;
	t_list	*closest;
	int		cost_a;
	int		cost_b;

	cost_a = ft_min(node->index, stacks->len_a - node->index);
	curr = *head_b;
	closest = find_closest(head_b, node);
	if (closest == (void *) 0)
		cost_b = 0;
	else
		cost_b = ft_min(closest->index, stacks->len_b - closest->index);
	return (cost_a + cost_b);
}

t_list	*ft_node_to_insert(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list	*curr;
	t_list	*cheapest_node;
	int		cheapest;
	int		cost;

	curr = *head_a;
	cheapest = -1;
	while (curr != (void *) 0)
	{
		cost = compute_cost(head_b, curr, stacks);
		if (cheapest == -1 || cost < cheapest)
		{
			cheapest_node = curr;
			cheapest = cost;
		}
		curr = curr->next;
 	}
	return (cheapest_node);
}

void	get_closest_to_top(t_list **head_b, t_list *node_to_insert, t_stacks *stacks)
{
	t_list	*curr;
	t_list	*closest;

	curr = *head_b;
	closest = find_closest(head_b, node_to_insert);
	while (*head_b != closest)
	{
		if (node_to_insert->index < stacks->len_b / 2)
			ft_rotate(head_b, (void *) 0, 'b');
		else
			ft_revrotate(head_b, (void *) 0, 'b');
	}
}

void	cost_based_insertion(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list *node_to_insert;

	while (*head_a != (void *) 0)
	{
		node_to_insert = ft_node_to_insert(head_a, head_b, stacks);
		while (*head_a != node_to_insert)
		{
			if (node_to_insert->index < stacks->len_a / 2)
				ft_rotate(head_a, (void *) 0, 'a');
			else
				ft_revrotate(head_a, (void *) 0, 'a');
		}
		get_closest_to_top(head_b, node_to_insert, stacks);
		ft_push(head_a, head_b, 'b', stacks);
	}
}

void	push_to_a(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list	*largest;

	largest = *head_b;
	while (largest->pos != stacks->len_b - 1)
		largest = largest->next;
	while (*head_b != largest)
	{
		if (largest->index < stacks->len_b / 2)
			ft_rotate(head_b, (void *) 0, 'b');
		else
			ft_revrotate(head_b, (void *) 0, 'b');
	}
	while (*head_b != (void *) 0)
		ft_push(head_a, head_b, 'a', stacks);
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
	cost_based_insertion(&lst_a, &lst_b, &stacks);
	push_to_a(&lst_a, &lst_b, &stacks);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
