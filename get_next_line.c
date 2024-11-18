/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:38:54 by mayilmaz          #+#    #+#             */
/*   Updated: 2024/11/18 15:58:34 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

char	*ft_last_part(char *buff)
{
	int a;
	int	i;
	char *s1;

	i = 0;
	a = ft_indexlen(buff, '\n');
	s1 = ft_calloc(((ft_indexlen(buff, '\0') - a) + 1), sizeof(char));
	if (!s1)
		return (free(s1), NULL);
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
char *ft_first_part(char *buff)
{
	char	*src;
	int		a;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	a = ft_indexlen(buff, '\n');
	src = ft_calloc((a + 2), sizeof(char));
	if (!src)
		return (NULL);
	while (i <= a)
	{
		src[i] = buff[i];
		i++;
	}
	return (src);
}

char	*ft_alloc(int fd, char *buff)
{
	char *readed;
	int	readed_len;

	readed = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!readed)
		return (NULL);
	readed_len = 1;
	while (!ft_strchr(readed) && readed_len != 0)
	{
		readed_len = read(fd, readed, BUFFER_SIZE);
		if (readed_len == -1)
			return (free(readed), NULL);
		buff = ft_strjoin(buff, readed);
	}
	free(readed);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*src;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) == -1)
		return(free(buff), NULL);
	
	buff = ft_alloc(fd, buff);
	if (!buff)
		return (NULL);
	src = ft_first_part(buff);
	buff = ft_last_part(buff);
	return (src);
}
