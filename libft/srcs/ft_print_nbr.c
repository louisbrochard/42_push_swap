/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:28 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 13:42:48 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int	ft_print_nbr(int n)
{
    int length_of_print;
    char    *str;

	if (n == -2147483648)
	{
		ft_print_str("-2147483648");
		return(11);
	}
    str = ft_itoa(n);
    length_of_print = ft_print_str(str);
    free(str);
    return (length_of_print);
}