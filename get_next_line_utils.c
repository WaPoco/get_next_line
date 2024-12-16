/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:21:27 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/16 21:38:30 by vpogorel         ###   ########.fr       */
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
