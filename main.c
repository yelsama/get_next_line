#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char *line;
	//char *s;


	fd = open("my.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("bad file\n");
		return (0);
	}
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}	
	// printf("%s", ptr = get_next_line(fd));
	// free(fd);
	// printf("%s", ptr = get_next_line(fd));
	//puts(get_next_line(fd));
	//puts(get_next_line(fd));

	// for (int i = 0; i < 100 ; i++)
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// 	free(s);
	// }
	//free(ptr);
	close(fd);
	 return (0);
}

//gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o aread && ./aread