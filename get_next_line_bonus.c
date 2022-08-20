/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:44:09 by ymohamed          #+#    #+#             */
/*   Updated: 2022/08/20 18:39:50 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_left(char *onboard)
{
	char	*left;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (onboard[i] != '\0' && onboard[i] != '\n')
		i++;
	if (onboard[i] == '\0')
	{
		free(onboard);
		return (NULL);
	}
	left = ft_calloc((ft_strlen(onboard) - i + 1), sizeof(char));
	if (!left)
		return (NULL);
	i++;
	while (onboard[i])
		left[c++] = onboard[i++];
	free(onboard);
	return (left);
}

char	*get_aline(char *onboard)
{	
	char	*line;
	int		i;

	i = 0;
	if (!onboard[0])
		return (NULL);
	while (onboard[i] != '\n' && onboard[i] != '\0')
		i++;
	i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, onboard);
	return (line);
}

char	*get_read_new_with_old(int fd, char *onboard)
{
	char		*block;
	int			redchar;

	block = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!block)
		return (NULL);
	redchar = (int)BUFFER_SIZE;
	while (redchar != 0 && !ft_strchr(block, '\n'))
	{
		redchar = read(fd, block, BUFFER_SIZE);
		if (block[0] == '\0')
			break ;
		block[redchar] = '\0';
		onboard = ft_strjoin(onboard, block);
	}
	if (redchar == -1)
	{
		if (onboard)
			free(onboard);
		free(block);
		return (NULL);
	}
	free(block);
	return (onboard);
}

char	*get_next_line(int fd)
{
	static char	*onboard[FILE_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	onboard[fd] = get_read_new_with_old(fd, onboard[fd]);
	if (!onboard[fd])
		return (NULL);
	line = get_aline(onboard[fd]);
	onboard[fd] = get_left(onboard[fd]);
	return (line);
}
