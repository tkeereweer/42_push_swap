/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:42:18 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/08/31 20:06:19 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move(char *str_dst, char *str_src, int i_len)
{
	int	i;

	if (str_dst <= str_src)
	{
		i = 0;
		while (i < i_len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
	{
		i = i_len - 1;
		while (i >= 0)
		{
			str_dst[i] = str_src[i];
			i--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i_len;
	char	*str_dst;
	char	*str_src;

	if (src == (void *) 0 && dst == (void *) 0)
		return (dst);
	i_len = (int) len;
	str_dst = (char *) dst;
	str_src = (char *) src;
	ft_move(str_dst, str_src, i_len);
	return (dst);
}
