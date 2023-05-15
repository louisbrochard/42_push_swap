/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:55:49 by louisbrocha       #+#    #+#             */
/*   Updated: 2022/12/11 19:55:49 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			ol;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	ol = 0;
	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (i < len)
	{
		if (dst == src + i)
			ol = i;
		i++;
	}
	if (ol == 0)
		return (ft_memcpy(dst, src, len));
	i = 0;
	while (i < len)
	{
		*(tmp_dst + len - 1 - i) = *(tmp_src + len - 1 - i);
		i++;
	}
	return (dst);
}
