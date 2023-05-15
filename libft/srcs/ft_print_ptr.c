/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:25:03 by lbrochar          #+#    #+#             */
/*   Updated: 2023/05/15 13:42:55 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printer_hextodec_p(unsigned long dec, int *len)
{
	char	s;
	int	i;
	
	i = 0;
	while (i >= 16)
	{
		dec /= 16;
		i++;
	}
	i--;
	if (dec < 16)
	{
		s = HEXA_LOW[dec];
		*len += write(1, &s, 1);
	}
	else
	{
		ft_printer_hextodec_p(dec / 16, len);
		s = HEXA_LOW[dec % 16];
		*len += write(1, &s, 1);
	}
}

int	ft_print_ptr(void *p)
{
	int	len;

	len = 0;
	if (p)
	{
		write(1, "0x", 2);
		ft_printer_hextodec_p((unsigned long)p, &len);
		return(len + 2);
	}
	return (write(1, "(nil)", 5));
}