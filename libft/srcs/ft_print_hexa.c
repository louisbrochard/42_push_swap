/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:44:57 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 13:42:44 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "../includes/ft_printf.h"

#define HEXA_UP "0123456789ABCDEF"
#define HEXA_LOW "0123456789abcdef"

void ft_printer_hextodec(long dec, int *len, char c)
{
    char s;
    int temp;
    int i;

    temp = dec;
    i = 1;
    while (temp >= 16)
    {
        temp /= 16;
        i++;
    }

    if (dec < 16)
    {
        if (c == 'X')
        {
            s = HEXA_UP[dec];
            *len += write(1, &s, 1);
        }
        else
        {
            s = HEXA_LOW[dec];
            *len += write(1, &s, 1);
        }
    }
    else
    {
        if (c == 'X')
        {
            ft_printer_hextodec(dec / 16, len, c);
            s = HEXA_UP[dec % 16];
            *len += write(1, &s, 1);
        }
        else
        {
            ft_printer_hextodec(dec / 16, len, c);
            s = HEXA_LOW[dec % 16];
            *len += write(1, &s, 1);
        }
    }
}

int ft_printer_x(unsigned int nb, char c)
{
    int len = 0;
    ft_printer_hextodec(nb, &len, c);
    return len;
}