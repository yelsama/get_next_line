#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd1;
	int fd2;
	int fd3;
	char *line;

	fd1 = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	fd3 = open("c.txt", O_RDONLY);
	if(fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("bad file\n");
		return (0);
	}
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}	
	close(fd1);
	close(fd2);
	close(fd3);
	 return (0);
}

//gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o abread && ./abread