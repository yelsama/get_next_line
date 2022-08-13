#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	char	*current;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
