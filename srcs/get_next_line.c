/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:40:11 by taehykim          #+#    #+#             */
/*   Updated: 2022/04/22 18:40:13 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_split_line(char **line, int nl)
{
	char	*temp;
	char	*arr;

	temp = ft_strdup(*line + nl + 1);
	(*line)[nl + 1] = '\0';
	arr = ft_strdup(*line);
	free(*line);
	*line = temp;
	return (arr);
}

char	*final_line(char **line)
{
	char	*arr;

	arr = *line;
	*line = NULL;
	if (ft_strlen(arr) == 0)
	{
		free(arr);
		arr = NULL;
		return (arr);
	}
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			read_size;
	int			nl;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		line[fd] = ft_strjoin(line[fd], buffer);
		nl = is_newline(line[fd]);
		if (nl >= 0)
			return (get_split_line(&line[fd], nl));
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	if (line[fd])
	{
		if (is_newline(line[fd]) >= 0)
			return (get_split_line(&line[fd], is_newline(line[fd])));
		else
			return (final_line(&line[fd]));
	}
	return (NULL);
}
