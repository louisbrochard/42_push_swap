/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:20:18 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/04 11:55:16 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(char **argv)
{
	int	i;
	int	len;

	len = 1;
	i = 1;
	while (argv[len])
		len++;
	while (i != len - 1)
	{
		if (ft_atoi2(argv[i]) > ft_atoi2(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_argv_is_nb(char *str)
{
	int		i;
	long	check;

	i = 0;
	check = ft_atoi2(str);
	if (check > 2147483647 || check < INT_MIN)
		return (1);
	if (sign(str[i]) == 1)
		i++;
	if (digit(str[i]) == 1)
	{
		while (digit(str[i]) == 1)
			i++;
	}
	else
		return (1);
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	ft_check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = i - 1;
	while (argv[i])
	{
		while (j != 0)
		{
			if (ft_atoi2(argv[i]) == ft_atoi2(argv[j]))
				return (1);
			j--;
		}
		i++;
		j = i - 1;
	}
	return (0);
}

int	ft_check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_argv_is_nb(argv[i]) == 1)
			return (1);
		i++;
	}
	if (ft_check_duplicate(argv) == 1)
		return (1);
	return (0);
}
