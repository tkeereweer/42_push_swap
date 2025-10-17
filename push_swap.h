/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:54:51 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/17 10:40:25 by mkeerewe         ###   ########.fr       */
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
	int	min_b;
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

void	ft_set_index(t_list **head);
int		ft_isnum(int c);
void	ret_error(void);
void	check_input(int argc, char *argv[]);
t_list	*ft_lstinit(int argc, char *argv[]);
int		ft_min(int a, int b);
void	ft_push(t_list **head_a, t_list **head_b, char stack);
// void	ft_push(t_list **head_a, t_list **head_b, char stack, t_stacks *stacks);
void	ft_swap(t_list **head_1, t_list **head_2, char stack);
void	ft_rotate(t_list **head_1, t_list **head_2, char stack);
void	ft_revrotate(t_list **head_1, t_list **head_2, char stack);

#endif
