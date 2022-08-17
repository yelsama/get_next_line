#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	//char *s;

	fd = open("my.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	//puts(get_next_line(fd));
	//puts(get_next_line(fd));

	// for (int i = 0; i < 100 ; i++)
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// 	free(s);
	// }
	close(fd);
	 return (0);
}

//gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o aread && ./aread