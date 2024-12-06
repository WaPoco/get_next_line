/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/06 22:38:43 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 	*buffer;
	char	*line;
	size_t	bytesRead;
	size_t	temp;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return NULL;
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	temp = 0;
	while (bytesRead != temp)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
				break;
			i++;
		}
		k += i;
		if (buffer[i] == '\n')
			break;
		temp = bytesRead;
		bytesRead += read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == temp - 1)
			break;
	}
	free(buffer);
	line = malloc(k + 1);
	read(fd, line, k);
	line[k] = '\0';
	return (buffer);
}

int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	write(1, line, 20);
	close(fd);
	return (1);
}