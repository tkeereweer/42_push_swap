/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_based_insertion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:39:39 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/26 11:55:15 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_cost(t_list **head_b, t_list *node, t_stacks *stacks)
{
	// cost_a = node->index
	t_list	*curr;
	t_list	*closest;

	curr = *head_b;
	closest = (void *) 0;
	stacks->cost_a = node;
	while (curr != (void *) 0)
	{
		if (closest == (void *) 0 || (curr->pos < node->pos && curr->pos > closest->pos))
			closest = curr;
		curr = curr->next;
	}
	if (closest == (void *) 0)
		return(0 + node->index);
	else
		return (closest->index + node->index);
}

t_list	*ft_node_to_insert(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list	*curr;
	t_list	*cheapest_node;
	int		cheapest;

	curr = *head_a;
	cheapest = -1;
	while (curr != (void *) 0)
	{
		if (cheapest == -1 || compute_cost(head_b, curr, stacks) < cheapest)
		{
			cheapest_node = curr;
			cheapest = compute_cost(head_b, curr, stacks);
		}
		curr = curr->next;
 	}
	return (cheapest_node);
}

void	cost_based_insertion(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
	t_list *node_to_insert;

	while (*head_a != (void *) 0)
	{
		node_to_insert = ft_node_to_insert(head_a, head_b, stacks);
		while (*head_a != node_to_insert)
			ft_rotate(head_a, (void *) 0, 'a');
		
		ft_push(head_a, head_b, 'b', stacks);
	}
}

void	push_to_a(t_list **head_a, t_list **head_b, t_stacks *stacks)
{
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
