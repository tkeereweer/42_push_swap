/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_based_insertion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:39:39 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/16 17:19:12 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
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

t_cost	compute_cost(t_list **head_b, t_list *node, t_stacks *stacks)
{
	t_list	*closest;
	int		cost_a;
	int		cost_b;
	t_cost	cost;

	cost.cost = 0;
	cost.node = node;
	cost_a = ft_min(node->index, stacks->len_a - node->index);
	cost.cost += cost_a;
	if (cost_a < node->index)
		cost.dir = 'r';
	else
		cost.dir = 'n';
	closest = find_closest(head_b, node);
	if (closest != (void *) 0)
	{
		cost_b = ft_min(closest->index, stacks->len_b - closest->index);
		cost.cost += cost_b;
		if (cost_b < closest->index && cost.dir != 'r')
			cost.dir = 'm';
		else if (cost_b >= closest->index && cost.dir != 'n')
			cost.dir = 'm';
	}
	if (cost.dir == 'r' || cost.dir == 'n')
		cost.cost = ft_max(cost_a, cost_b);
	return (cost);
}

t_cost	ft_node_to_insert(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list	*curr;
	t_cost	cheapest_cost;
	t_cost	curr_cost;

	curr = *head_a;
	cheapest_cost.cost = -1;
	while (curr != (void *) 0)
	{
		curr_cost = compute_cost(head_b, curr, stacks);
		if (cheapest_cost.cost == -1 || curr_cost.cost < cheapest_cost.cost)
		{
			cheapest_cost.node = curr;
			cheapest_cost.cost = curr_cost.cost;
		}
		curr = curr->next;
	}
	return (cheapest_cost);
}

// void	get_closest_to_top(t_list **head_b, t_list *node_to_insert,
// 			t_stacks *stacks)
// {
// 	t_list	*closest;

// 	closest = find_closest(head_b, node_to_insert);
// 	while (*head_b != closest)
// 	{
// 		if (closest->index < stacks->len_b / 2)
// 			ft_rotate(head_b, (void *) 0, 'b');
// 		else
// 			ft_revrotate(head_b, (void *) 0, 'b');
// 	}
// }

void	cost_based_insertion(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list	*closest;
	t_cost	cost;

	while (*head_a != (void *) 0)
	{
		cost = ft_node_to_insert(head_a, head_b, stacks);
		closest = find_closest(head_b, cost.node);
		while (cost.dir != 'm' && *head_a != cost.node && *head_b != closest)
		{
			if (cost.dir == 'n')
				ft_rotate(head_a, head_b, 'r');
			else
				ft_revrotate(head_a, head_b, 'r');
		}
		while (*head_a != cost.node)
		{
			if (cost.node->index < stacks->len_a / 2)
				ft_rotate(head_a, (void *) 0, 'a');
			else
				ft_revrotate(head_a, (void *) 0, 'a');
		}
		while (*head_b != closest)
		{
			if (closest->index < stacks->len_b / 2)
				ft_rotate(head_b, (void *) 0, 'b');
			else
				ft_revrotate(head_b, (void *) 0, 'b');
		}
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
