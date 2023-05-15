/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/12/11 19:52:04 by louisbrocha       #+#    #+#             */
/*   Updated: 2022/12/11 19:52:04 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*d1;
	unsigned char		*d2;
	size_t				i;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
