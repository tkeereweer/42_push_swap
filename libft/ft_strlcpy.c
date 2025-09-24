/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:09:09 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/08/23 14:22:28 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

// int	main(void)
// {
// 	char	*dst;
// 	char	*src = "hello";

// 	dst = malloc(8);
// 	dst[0] = '1';
// 	dst[1] = '2';
// 	dst[2] = '3';
// 	dst[3] = '4';
// 	dst[4] = '5';
// 	dst[5] = '6';
// 	dst[6] = '7';
// 	dst[7] = '\0';
// 	ft_strlcpy(dst, src, 3);
// 	return (0);
// }
