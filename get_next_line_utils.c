/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:27 by vpogorel          #+#    #+#             */
/*   Updated: 2025/08/01 14:56:42 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*new_line(char *line, char c)
{
	size_t	k;
	size_t	len_line;
	char	*new_line;

	k = 0;
	len_line = ft_strlen(line);
	new_line = malloc(len_line + 2);
	while (k < len_line)
	{
		new_line[k] = line[k];
		k++;
	}
	free(line);
	new_line[len_line] = c;
	new_line[len_line + 1] = '\0';
	return (new_line);
}

void	change_buffer(char *buffer, size_t start)
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

char	*buffer_check(char *buffer, char *line)
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

char	*free_mem(char *line, int bytesRead)
{
	if (bytesRead == -1)
		free(line);
	return (NULL);
}
