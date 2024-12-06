/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/06 18:31:52 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 	*buffer;
	size_t	i;
	size_t	k;

	i = 0;
	k = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	while (read(fd, &buffer[i], BUFFER_SIZE) > 0)
	{
		while (i < k*BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
				break;
			i++;
		}
		if (buffer[i] == '\n')
			break;
		k++;
	}
	if ((int)i == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
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