/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/07 19:15:04 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 	*buffer;
	char	*line;
	static size_t	bytesRead;
	size_t	i;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	line = (char *)malloc(1);
	line[0] = '\0';
	if (!buffer)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	bytesRead = -1;
	while (bytesRead != 0)
	{
		i = 0;
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytesRead == - 1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		while (i < bytesRead)
		{
			if (buffer[i] == '\0' || buffer[i] == '\n')
				return (new_line(line, buffer, i));
			i++;
		}
		line = new_line(line, buffer, i);
	}
	free(buffer);
	return (line);
} 

int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s \n", line);
	close(fd);
	return (1);
}