/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:20 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/16 22:22:48 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	change_buffer(char *buffer, size_t start)
{
	size_t	i;

	i = 0;
	while (start + i < BUFFER_SIZE && start != 0)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

static char	*buffer_check(char *buffer, char *line)
{
	size_t	i;
	size_t	max;
	size_t	index_end;

	max = ft_strlen(buffer);
	i = 0;
	if (max == 0)
		return (line);
	index_end = BUFFER_SIZE - 1;
	while (i < max)
	{
		if (buffer[i] == '\n')
		{
			index_end = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < index_end + 1)
		line = new_line(line, buffer[i++]);
	change_buffer(buffer, index_end + 1);
	return (line);
}

static char	*free_mem(char *line, int bytesRead)
{
	if (bytesRead == -1)
		free(line);
	return (NULL);
}

static char	*create_new_line(int fd, char *buffer)
{
	char		*line;
	size_t		bytesread;
	size_t		temp;
	size_t		len_line;

	temp = -1;
	line = NULL;
	bytesread = 0;
	len_line = 0;
	while (bytesread != temp)
	{
		temp = bytesread;
		line = buffer_check(buffer, line);
		len_line = ft_strlen(line);
		if (line != NULL && line[len_line - 1] == '\n')
			return (line);
		bytesread += read(fd, buffer, BUFFER_SIZE);
		if (bytesread < temp)
			return (free_mem(line, (int)bytesread));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
		return (NULL);
	return (create_new_line(fd, buffer));
}
/*
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
*/
