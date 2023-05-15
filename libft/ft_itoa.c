/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:52:02 by lbrochar          #+#    #+#             */
/*   Updated: 2022/12/12 16:59:17 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_power(int n, int p)
{
	int	res;

	res = 1;
	while (p != 0)
	{
		res *= n;
		p--;
	}
	return (res);
}

static char	*ft_fill_str(long int *temp, char *str, int *nbr_len, int *k)
{
	if (*temp < 0)
	{
		str[*k] = '-';
		*temp *= -1;
		*nbr_len = *nbr_len - 1;
		*k = *k + 1;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			nbr_len;
	int			i;
	int			k;
	long int	temp;

	i = 0;
	k = 0;
	nbr_len = ft_nbrlen(n);
	temp = n;
	str = malloc(sizeof(char) * (nbr_len + 1));
	if (str == NULL)
		return (0);
	ft_fill_str(&temp, str, &nbr_len, &k);
	while (k != ft_nbrlen(n))
	{
		str[k] = temp / (ft_power(10, nbr_len - i - 1)) + 48;
		temp %= ft_power(10, nbr_len - i - 1);
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
