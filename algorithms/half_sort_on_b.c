/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_sort_on_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/24 13:19:14 by mkeerewe         ###   ########.fr       */
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

void	half_sort_on_b(int argc, t_list **head_a, t_list **head_b)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i <= (argc - 1) / 2)
	{
		node = *head_a;
		while (node->pos != i)
			node = node->next;
		if (node->index > argc - 3 - i)
		{
			while (node->index != 0)
				ft_revrotate(head_a, (void *) 0, 'a');
		}
		else
			while (node->index != 0)
				ft_rotate(head_a, (void *) 0, 'a');
		ft_push(head_a, head_b, 'b');
		i++;
	}
	if (ft_is_sorted(*head_a) == 0)
		ft_swap(head_a, (void *) 0, 'a');
}

void	sort_stack_a(int argc, t_list **head_a)
{
	t_list	*node;

	while (ft_is_sorted(*head_a) == 0)
	{
		node = *head_a;
		if (node->pos != argc - 2 && node->pos > node->next->pos)
			ft_swap(head_a, (void *) 0, 'a');
		ft_rotate(head_a, (void *) 0, 'a');
	}
}

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
	half_sort_on_b(argc, &lst_a, &lst_b);
	sort_stack_a(argc, &lst_a);
	push_to_a(&lst_a, &lst_b);
	return (0);
}
