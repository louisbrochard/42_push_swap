/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:12:32 by louisbrocha       #+#    #+#             */
/*   Updated: 2022/12/12 16:41:02 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lenmalloc;

	if (s == NULL)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	lenmalloc = len;
	if (ft_strlen(s + start) < len)
		lenmalloc = ft_strlen(s + start);
	str = malloc(sizeof(char) * (lenmalloc + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, ((char *)s + start), (lenmalloc + 1));
	return (str);
}
