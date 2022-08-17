#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;
	int		c;

	ptr = (char *)s;
	c = 0;
	while (ptr[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	m;
	int		i;

	ptr = (char *)s;
	m = (char )c;
	i = 0;
	while (ptr[i] != '\0')
	{
		i++;
	}
	while (ptr[i] != m && i != 0)
	{
		i--;
	}
	if (ptr[i] != m)
		return (0);
	return (&ptr[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	size_t	l;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) *1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	fs = malloc(sizeof(char) * ( ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fs)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		fs[i] = s1[i];
	l = 0;
	while (s2[l] != '\0')
		fs[i++] = s2[l++];
	fs[i] = s2[l];
	free(s1);
	return (fs);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	c;

	c = 0;
	while (src[c] && src[c] != '\n')
	{
		dest[c] = src[c];
		c++;
	}
	if (src[c] == '\n')
	{
		dest[c] = '\n';
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
