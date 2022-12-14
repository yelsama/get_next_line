/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:46:24 by ymohamed          #+#    #+#             */
/*   Updated: 2022/08/20 18:39:32 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	m;
	int		i;

	ptr = (char *)s;
	m = (char )c;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == m)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	size_t	l;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	fs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fs)
		return (NULL);
	l = ft_strlen(s1);
	i = -1;
	while (++i < l)
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

void	*ft_calloc(size_t count, size_t size)
{
	char				*ptr;
	unsigned long		i;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
