/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:54:51 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/13 18:46:51 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	ft_push(t_list **head_a, t_list **head_b, char stack);
void	ft_swap(t_list **head_1, t_list **head_2, char stack);
void	ft_rotate(t_list **head_1, t_list **head_2, char stack);
void	ft_revrotate(t_list **head_1, t_list **head_2, char stack);

#endif
