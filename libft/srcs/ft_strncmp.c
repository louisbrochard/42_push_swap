/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:38:36 by lbrochar          #+#    #+#             */
/*   Updated: 2023/05/15 13:29:00 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
