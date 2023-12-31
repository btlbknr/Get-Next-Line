/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbakaner <fbakaner@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:13:35 by fbakaner          #+#    #+#             */
/*   Updated: 2023/02/23 13:52:03 by fbakaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_read(char *str)
{
	int		i;
	int		j;
	char	*next_str;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	next_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!next_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		next_str[j++] = str[i++];
	next_str[j] = 0;
	free(str);
	return (next_str);
}

char	*read_first_line(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = 0;
	return (new_str);
}

char	*read_line(char *str, int fd)
{
	char	*line;
	int		line_i;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line_i = 1;
	while (ft_strchr(str, '\n') == 0 && line_i != 0)
	{
		line_i = read(fd, line, BUFFER_SIZE);
		if (line_i == -1)
		{
			free(str);
			free(line);
			return (0);
		}
		line[line_i] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = read_line(str, fd);
	if (!str)
		return (NULL);
	line = read_first_line(str);
	str = next_read(str);
	return (line);
}
