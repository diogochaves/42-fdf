/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:14:07 by dchaves-          #+#    #+#             */
/*   Updated: 2022/02/09 20:27:45 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char **buffer);
static char	*set_buffer(char *buffer, char *file);
static char	*read_buffer(char **buffer, char *new_line, int size);

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	line = read_line(fd, &buffer[fd]);
	return (line);
}

static char	*read_line(int fd, char **buffer)
{
	char	*file;
	char	*line;
	int		size;

	file = malloc(BUFFER_SIZE + 1);
	if (!file)
		return (NULL);
	size = 1;
	while (!ft_strchr(*buffer, '\n') && size > 0)
	{
		size = read(fd, file, BUFFER_SIZE);
		if (size > 0)
		{
			file[size] = '\0';
			*buffer = set_buffer(*buffer, file);
		}
	}
	line = read_buffer(buffer, ft_strchr(*buffer, '\n'), size);
	free(file);
	return (line);
}

static char	*set_buffer(char *buffer, char *file)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, file);
	free(buffer);
	buffer = NULL;
	return (new_buffer);
}

static char	*read_buffer(char **buffer, char *new_line, int size)
{
	char	*line;

	line = *buffer;
	if (size > 0)
	{
		*buffer = ft_strdup(new_line + 1);
		*(new_line + 1) = '\0';
	}
	else
	{
		if (ft_strlen(*buffer) == 0)
		{
			free(*buffer);
			line = NULL;
		}
		*buffer = NULL;
	}
	return (line);
}
