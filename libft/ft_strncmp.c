/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:38:36 by lbrochar          #+#    #+#             */
/*   Updated: 2022/12/12 16:39:15 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	if (length == 0)
		return (0);
	while ((*first == *second) && (*first != '\0')
		&& (*second != '\0') && --length)
	{
		first++;
		second++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}
