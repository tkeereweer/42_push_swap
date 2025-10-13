/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:49:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/13 16:14:45 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mean(int *arr, int len)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < len)
	{
		sum += arr[i];
		i++;
	}
	return (sum / len);
}

int	get_mean_idx(int argc, t_list **head_a, int i, int chunks)
{
	t_list	*node;
	int		*arr;
	int		j;
	int		ret;

	node = *head_a;
	arr = (int *) malloc(((argc - 1) / chunks) * sizeof(int));
	if (arr == (void *) 0)
		return (-1);
	j = 0;
	while (j < ((argc - 1) / chunks))
	{
		if (node->pos < ((argc - 1) / chunks) * (i + 1))
		{
			arr[j] = node->index;
			j++;
		}
		node = node->next;
	}
	ret = ft_mean(arr, j);
	free(arr);
	return (ret);
}

void	chunks_to_b(int argc, t_list **head_a, t_list **head_b, int chunks)
{
	int		i;
	int		j;
	int		mean_idx;

	i = 0;
	mean_idx = -1;
	while (i < chunks)
	{
		j = 0;
		while (j < (argc - 1) / chunks)
		{
			if ((*head_a)->pos < ((argc - 1) / chunks) * (i + 1))
			{
				ft_push(head_a, head_b, 'b');
				mean_idx = get_mean_idx(argc, head_a, i, chunks);
				j++;
			}
			else if (mean_idx > ((argc - 2) - (i + 1) * j) / 2)
				ft_revrotate(head_a, (void *) 0, 'a');
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

int	main(int argc, char *argv[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	lst_a = ft_lstinit(argc, argv);
	lst_b = (void *) 0;
	if (argc - 1 < 200)
		chunks_to_b(argc, &lst_a, &lst_b, (argc - 1) / 18);
	else
		chunks_to_b(argc, &lst_a, &lst_b, (argc - 1) / 45);
	push_largest_to_a(argc, &lst_a, &lst_b);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
