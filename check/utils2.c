/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:47:48 by lbrochar          #+#    #+#             */
/*   Updated: 2023/05/17 15:47:58 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*ft_backup(char *backup)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen2(backup) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (backup[i])
		s[c++] = backup[i++];
	s[c] = '\0';
	free(backup);
	return (s);
}

char	*ft_get_line(char *backup)
{
	char	*s;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		s[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		s[i] = backup[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_backup(int fd, char *backup)
{
	char	*buffer;
	int		nb_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb_bytes = 1;
	while (!ft_strchr2(backup, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_bytes] = '\0';
		backup = ft_strjoin2(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_backup(backup);
	return (line);
}
