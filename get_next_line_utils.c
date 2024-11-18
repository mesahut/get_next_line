#include <stdlib.h>

int	ft_indexlen(char *s, int c)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != c)
		i++;
	return (i);
}
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	byte;
	char	*x;

	i = 0;
	byte = nmemb * size;
	if (size && (byte / size != nmemb))
		return (0);
	x = (char *)malloc(byte);
	if (!x)
		return (0);
	while (byte > 0)
	{
		x[i] = 0;
		i++;
		byte--;
	}
	return ((void *)x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*dst;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc(((len1 + len2) * sizeof(char)) + 1);
	if (!dst)
		return (0);
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		dst[i] = s2[i - len1];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
