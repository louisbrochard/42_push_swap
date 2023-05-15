/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:06:35 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 13:43:01 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int ft_print_unsigned(int n)
{
    unsigned int u = (unsigned int)n;
    int len;
    char c;

    len = ft_nbrlen(u); 
    if (u >= 10)
        ft_print_unsigned(u / 10);
    c = u % 10 + '0';
    ft_print_char(c);
    return (len);
}
