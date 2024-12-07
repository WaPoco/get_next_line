/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:27 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/07 19:09:34 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)

{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*new_line(char *line, char *buffer, size_t i)
{
	size_t	k;
	size_t	len_line;
	char	*new_line;

	k = 0;
	len_line = ft_strlen(line);
	new_line = malloc(i + len_line + 1);
	while (k < len_line)
	{
		new_line[k] = line[k];
		k++;
	}
	free(line);
	k = 0;
	while (k < i)
	{
		new_line[len_line + k] = buffer[k];
		k++;
	}
	new_line[len_line + k] = '\0';
	return (new_line);
}
