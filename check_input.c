/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:34:20 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/20 08:32:19 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int_lim(char *argv[], int i)
{
	long	num;
	int		sign;
	int		j;

	sign = 1;
	j = 0;
	if (argv[i][j] == '-')
	{
		sign = -1;
		j++;
	}
	num = 0;
	while (argv[i][j])
	{
		num = num * 10 + (argv[i][j] - '0');
		if (sign == 1 && num > 2147483647)
			ret_error();
		if (sign == -1 && num > 2147483648)
			ret_error();
		j++;
	}
}

void	check_nums(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
			{
				j++;
				continue ;
			}
			else if (ft_isnum(argv[i][j]) == 0)
				ret_error();
			j++;
		}
		check_int_lim(argv, i);
		i++;
	}
}

void	check_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (j == i)
			{
				j++;
				continue ;
			}
			if (ft_atoi(argv[i]) - ft_atoi(argv[j]) == 0)
				ret_error();
			j++;
		}
		i++;
	}
}

void	check_input(int argc, char *argv[])
{
	check_nums(argc, argv);
	check_duplicates(argc, argv);
}
