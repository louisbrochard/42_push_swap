/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:46:29 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 14:20:36 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_handle_format(const char *p, va_list args)
{
	int	count;

	count = 0;
	if (*p == 's')
		count += ft_print_str(va_arg(args, const char *));
	else if (*p == 'd' || *p == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (*p == 'x' || *p == 'X')
		count += ft_printer_x(va_arg(args, int), *p);
	else if (*p == '%')
		count += ft_print_char(*p);
	else if (*p == 'u')
		count += ft_print_unsigned(va_arg(args, int));
	else if (*p == 'c')
		count += ft_print_char((char)va_arg(args, int));
	else if (*p == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	const char *p = format;

	count = 0;
	va_start(args, format);
	while (*p != '\0') 
	{
		if (*p == '%')
		{
			p++;
			count += ft_handle_format(p, args);
		}
		else
			count += ft_print_char(*p);
		p++;
	}
	va_end(args);
	return (count);
}