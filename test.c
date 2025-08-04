#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("1.line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("2.line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("3.line: %s", line);
	free(line);
	close(fd);
	return (1);
}