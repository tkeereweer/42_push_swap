/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_chunking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:46:17 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 14:05:51 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/13 16:20:56 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **head_a, int argc)
{
	while (is_sorted(head_a) == 0)
	{
		if ((*head_a)->pos != argc - 2 && (*head_a)->next->pos < (*head_a)->pos)
			ft_swap(head_a, (void *) 0, 'a');
		if (is_sorted(head_a) == 0)
			ft_rotate(head_a, (void *) 0, 'a');
	}
}

void	chunks_to_b(int argc, t_list **head_a, t_list **head_b, int chunks)
{
	int		i;
	int		j;

	i = 0;
	while (i < chunks)
	{
		j = 0;
		while (j < (argc - 1) / chunks)
		{
			if ((*head_a)->pos < ((argc - 1) / chunks) * (i + 1))
			{
				ft_push(head_a, head_b, 'b');
				j++;
			}
			else
				ft_rotate(head_a, (void *) 0, 'a');
		}
		i++;
	}
	while (*head_a)
		ft_push(head_a, head_b, 'b');
}

void	push_largest_to_a(int argc, t_list **head_a, t_list **head_b)
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
		ft_push(head_a, head_b, 'a');
		i++;
	}
}

int	run_prog(t_list **head_a, t_list **head_b, int argc)
{
	if (argc - 1 == 2)
	{
		ft_swap(head_a, (void *) 0, 'a');
		ft_lstclear(head_a);
		return (0);
	}
	else if (argc - 1 == 3)
	{
		sort_three(head_a, argc);
		ft_lstclear(head_a);
		return (0);
	}
	else if (argc - 1 < 40)
	{
		sort_on_b(argc, head_a, head_b);
		push_to_a(head_a, head_b);
		ft_lstclear(head_a);
		ft_lstclear(head_b);
		return (0);
	}
	else if (argc - 1 < 200)
		chunks_to_b(argc, head_a, head_b, (argc - 1) / 18);
	else
		chunks_to_b(argc, head_a, head_b, (argc - 1) / 45);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	lst_a = ft_lstinit(argc, argv);
	lst_b = (void *) 0;
	if (is_sorted(&lst_a) == 1)
	{
		ft_lstclear(&lst_a);
		return (0);
	}
	if (run_prog(&lst_a, &lst_b, argc) == 0)
		return (0);
	push_largest_to_a(argc, &lst_a, &lst_b);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
