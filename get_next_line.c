#include "get_next_line.h"

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
	left = malloc(sizeof(char) * (ft_strlen(onboard) - i + 1));
	if (!left)
		return(NULL);
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
	if (!onboard)
		return (NULL);
	while (onboard[i] != '\n' && onboard[i] != '\0')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, onboard);
	return (line);
}

char	*get_read_new_with_old(int fd,char *onboard)
{
	char		*block;
	int			redchar;

	block = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!block)
		return (NULL);
	redchar = (int)BUFFER_SIZE;
	while (redchar !=0 && !ft_strrchr(block, '\n'))
	{
		redchar = read(fd, block, BUFFER_SIZE);
		block[redchar] = '\0';
		onboard = ft_strjoin(onboard, block);
	}
	if (redchar == -1)
	{
		if (onboard)
			free(onboard);
		free(block);
		return(NULL);
	}
	free(block);
	return (onboard);
}

char	*get_next_line(int fd)
{
	static char	*onboard;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	onboard = get_read_new_with_old(fd, onboard);
	if (!onboard)
		return(NULL);
	line = get_aline(onboard);
	onboard = get_left(onboard);
	return (line);
}
