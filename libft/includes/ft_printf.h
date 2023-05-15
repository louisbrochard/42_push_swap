/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:30:56 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/02/12 17:30:56 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int     ft_printform (va_list args, const char c);
size_t  ft_strlen(const char *str);
int     ft_print_uns_nbr (int n);
char    *ft_uitoa(unsigned int n);
int ft_print_char (char c);
int ft_print_hex_low (unsigned int args);
void    ft_print_hex_low2 (unsigned int args);
int ft_print_hex_up (unsigned int args);
void    ft_print_hex_up2 (unsigned int args);
int	ft_print_nbr(int n);
char	*ft_itoa(int n);
int ft_print_percent(void);
int ft_print_str (const char  *str);
int ft_print_unsigned(int n);
int ft_printer_x(unsigned int nb, char c);
int	ft_print_ptr(void *p);

#endif