/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:59 by mayilmaz          #+#    #+#             */
/*   Updated: 2024/11/20 15:23:06 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5

# endif

char	*ft_calloc(int nmemb, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchr(const char *s);
int		ft_strlen(const char *s);
int		ft_indexlen(const char *s, int c);

#endif