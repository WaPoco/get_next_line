/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/09 22:17:44 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	free_mem(char *buffer, char *line, int bytesRead)
{
	if (bytesRead == - 1)
	{
		free(buffer);
		free(line);
	}
}
static char	*create_new_line(int fd, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	bytesRead;

	bytesRead = -1;
	line = NULL;
	while (bytesRead != 0)
	{
		i = 0;
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		free_mem(buffer, line, (int)bytesRead);
		while (i < bytesRead)
		{
			if (buffer[i] == '\0')
				return (new_line(line, buffer, bytesRead, i));
			else if (buffer[i] == '\n')
				return (new_line(line, buffer, bytesRead, i + 1));
			i++;
		}
		line = new_line(line, buffer, bytesRead, i);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char 			*buffer;
	char			*line;

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

	line = get_next_line(fd);
	printf("%s \n", line);
	free(line);
	close(fd);
	return (1);
}
*/

