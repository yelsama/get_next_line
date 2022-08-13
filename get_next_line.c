#include "get_next_line.h"

static char	*now_get_carry(char *all)
{
	int		i;
	char	*ptr;
	char	*carry;

	i = 0;
	ptr = all;
	carry = NULL;
	while (all[i] != '\n' && all[i] != '\0')
		i++;
	i++;
	carry = ft_strjoin(carry, ptr + i);
	//puts(carry); ////////////////////////
	return (carry);
}

static char	*now_get_line(char *all)
{
	int		i;
	char	*ptr;
	char	*line;
	char	temp;

	i = 0;
	ptr = all;
	line = NULL;
	while (all[i] != '\n' && all[i] != '\0')
		i++;
	temp = all[i + 1];
	if (all[i] == '\n')
			all[i + 1] = '\0';
	line = ft_strjoin(line, all);
	all [i + 1] = temp;
	//printf("%s",line);  //////////////
	return (line);
}

static char	*get_aline_and_next(int fd, char *all, size_t BUFFER_SIZE)
{
	char		*block;
	int		redchar;

	block = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!block)
		return (NULL);
	redchar = (int)BUFFER_SIZE;
	while (redchar == (int)BUFFER_SIZE)
	{
		redchar = read(fd, block, BUFFER_SIZE);
		block[BUFFER_SIZE] = '\0';
		if (redchar == -1)
			{
				free (block);
				free(all);
			}
		if (ft_strrchr(block, '\n') || ft_strlen(block) < BUFFER_SIZE)
			{
				all = ft_strjoin(all, block);
				break;
			}
		all = ft_strjoin(all, block);
	}
	free (block);
	return (all);
}

char	*get_next_line(int fd)
{
	char		*all;
	char		*line;
	static char	*carry;
	int			BUFFER_SIZE;

	BUFFER_SIZE = 5;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	//carry = NULL;
	all = get_aline_and_next(fd, line, BUFFER_SIZE);
	all  = ft_strjoin(carry, all);
	line = now_get_line(all);
	carry = now_get_carry(all);
	return (line);
}
