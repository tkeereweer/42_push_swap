/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_half_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/24 15:57:10 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *head)
{
	while (head->next != (void *) 0)
	{
		if (head->pos > head->next->pos)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_is_revsorted(t_list *head)
{
	while (head->next != (void *) 0)
	{
		if (head->pos < head->next->pos)
			return (0);
		head = head->next;
	}
	return (1);
}

void	small_half_to_b(int argc, t_list **head_a, t_list **head_b)
{
	int		i;

	i = 0;
	while (i <= (argc - 1) / 2)
	{
		while ((*head_a)->pos > (argc - 1) / 2)
			ft_rotate(head_a, (void *) 0, 'a');
		ft_push(head_a, head_b, 'b');
		i++;
	}
}

void	sort_stacks(int argc, t_list **head_a, t_list **head_b)
{
	t_list	*node_a;
	t_list	*node_b;

	while (ft_is_sorted(*head_a) == 0 || ft_is_revsorted(*head_b) == 0)
	{
		node_a = *head_a;
		node_b = *head_b;
		if (node_a->pos != argc - 2 && node_a->pos > node_a->next->pos && node_b->pos != 0 && node_b->pos < node_b->next->pos)
			ft_swap(head_a, head_b, 's');
		else if (node_a->pos != argc - 2 && node_a->pos > node_a->next->pos)
			ft_swap(head_a, (void *) 0, 'a');
		else if (node_b->pos != 0 && node_b->pos < node_b->next->pos)
			ft_swap(head_b, (void *) 0, 'b');
		if (ft_is_sorted(*head_a) == 1)
			ft_rotate(head_b, (void *) 0, 'b');
		else if (ft_is_revsorted(*head_b) == 1)
			ft_rotate(head_a, (void *) 0, 'a');
		else
			ft_rotate(head_a, head_b, 'r');
	}
}

// void	sort_stack_a(int argc, t_list **head_a)
// {
// 	t_list	*node;

// 	while (ft_is_sorted(*head_a) == 0)
// 	{
// 		node = *head_a;
// 		if (node->pos != argc - 2 && node->pos > node->next->pos)
// 			ft_swap(head_a, (void *) 0, 'a');
// 		ft_rotate(head_a, (void *) 0, 'a');
// 	}
// }

// void	revsort_stack_b(t_list **head_b)
// {
// 	t_list	*node;
	
// 	while (ft_is_revsorted(*head_b) == 0)
// 	{
// 		node = *head_b;
// 		if (node->pos != 0 && node->pos < node->next->pos)
// 			ft_swap(head_b, (void *) 0, 'b');
// 		ft_rotate(head_b, (void *) 0, 'b');
// 	}
// }

void	push_to_a(t_list **head_a, t_list **head_b)
{
	while (*head_b != (void *) 0)
	{
		ft_push(head_a, head_b, 'a');
	}
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc < 2)
		return (0);
	lst_a = ft_lstinit(argc, argv);
	lst_b = (void *) 0;
	small_half_to_b(argc, &lst_a, &lst_b);
	// sort_stack_a(argc, &lst_a);
	// revsort_stack_b(&lst_b);
	sort_stacks(argc, &lst_a, &lst_b);
	push_to_a(&lst_a, &lst_b);
	return (0);
}
