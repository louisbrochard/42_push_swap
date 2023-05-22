/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:28:11 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/22 16:42:29 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	s(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	digit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

long	ft_atoi2(const char *str)
{
	long	neg;
	int		i;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
