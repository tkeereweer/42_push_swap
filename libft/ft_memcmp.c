/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:42:18 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/08/30 15:56:06 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str_s1;
	char	*str_s2;

	if (n < 1)
		return (0);
	i = 0;
	str_s1 = (char *) s1;
	str_s2 = (char *) s2;
	while (i < n)
	{
		if ((unsigned char) str_s1[i] != (unsigned char) str_s2[i])
			return ((unsigned char) str_s1[i] - (unsigned char) str_s2[i]);
		i++;
	}
	return ((unsigned char) str_s1[i - 1] - (unsigned char) str_s2[i - 1]);
}
