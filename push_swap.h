/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:54:51 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/16 17:54:48 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int	len_a;
	int	len_b;
	int	chunks;
	int	upper;
	int	lower;
}	t_stacks;

typedef struct s_cost
{
	t_list	*node;
	int		cost;
	char	dir;
}	t_cost;

void	check_input(int argc, char *argv[]);
t_list	*ft_lstinit(int argc, char *argv[]);
// void	ft_push(t_list **head_a, t_list **head_b, char stack);
void	ft_push(t_list **head_a, t_list **head_b, char stack, t_stacks *stacks);
void	ft_swap(t_list **head_1, t_list **head_2, char stack);
void	ft_rotate(t_list **head_1, t_list **head_2, char stack);
void	ft_revrotate(t_list **head_1, t_list **head_2, char stack);

#endif
