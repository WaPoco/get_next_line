/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/10 22:26:40 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_mem(char *buffer, char *line, int bytesRead)
{
	if (bytesRead == -1)
	{
		free(buffer);
		free(line);
	}
	return (NULL);
}

static char	*create_new_line(int fd, char *buffer)
{
	char	*line;
	size_t	bytesread;
	size_t	temp;

	temp = -1;
	line = NULL;
	bytesread = 0;
	while (bytesread != temp)
	{
		temp = bytesread;
		bytesread += read(fd, buffer, 1);
		if (bytesread < temp)
			return (free_mem(buffer, line, (int)bytesread));
		else if (bytesread > temp)
		{
			if (buffer[0] == '\0')
				return (new_line(line, buffer[0]));
			else if (buffer[0] == '\n')
				return (new_line(line, buffer[0]));
			line = new_line(line, buffer[0]);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	if (fcntl(fd, F_GETFD) == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = create_new_line(fd, buffer);
	free(buffer);
	return (line);
}
/*
int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;
	int	i;
	int k =bytesRead 0;

	i = 0;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (1);
}
*/
