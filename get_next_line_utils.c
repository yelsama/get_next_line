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

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->current = content;
	n->next = 0;
	return (n);
}

// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (tmp->next == 0)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (tmp);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == 0)
	{
		*lst = new;
		lst[0]->next = 0;
	}
	else
	{
		temp = (*lst);
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
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
	size_t	m;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) *1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1);
	m = ft_strlen(s2);
	fs = malloc(sizeof(char) * (l + m + 1));
	if (!fs)
		return (NULL);
	i = -1;
	while (++i < l)
		fs[i] = s1[i];
	l = 0;
	while (s2[l] != '\0')
		fs[i++] = s2[l++];
	fs[i] = s2[l];
	return (fs);
}
