/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:14:50 by mayilmaz          #+#    #+#             */
/*   Updated: 2024/11/22 13:55:18 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_last_part(char *buff)
{
	int		a;
	int		i;
	char	*s1;

	i = 0;
	a = 0;
	while (buff[a] && buff[a] != '\n')
		a++;
	if (!buff[a])
		return (free(buff), NULL);
	s1 = ft_calloc(((ft_strlen(buff) - a)), sizeof(char));
	if (!s1)
		return (NULL);
	a++;
	while (buff[a] != '\0')
	{
		s1[i] = buff[a];
		i++;
		a++;
	}
	free(buff);
	return (s1);
}

char	*ft_first_part(char *buff)
{
	char	*src;
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (!buff[a])
		return (NULL);
	while (buff[a] && buff[a] != '\n')
		a++;
	src = ft_calloc((a + 2), sizeof(char));
	if (!src)
		return (NULL);
	while (i <= a && buff[i] != '\0')
	{
		src[i] = buff[i];
		i++;
	}
	return (src);
}

char	*ft_alloc(int fd, char *buff)
{
	char	*readed;
	int		readed_len;

	readed = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!readed)
		return (NULL);
	readed_len = 1;
	while (!ft_strchr(readed) && readed_len != 0)
	{
		readed_len = read(fd, readed, BUFFER_SIZE);
		if (readed_len == -1)
			return (free(readed), NULL);
		readed[readed_len] = '\0';
		buff = ft_strjoin(buff, readed);
	}
	free(readed);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[2048];
	char		*src;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	buff[fd] = ft_alloc(fd, buff[fd]);
	if (!buff[fd])
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	src = ft_first_part(buff[fd]);
	buff[fd] = ft_last_part(buff[fd]);
	return (src);
}
