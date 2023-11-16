/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/15 17:08:57 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *read_cicle(char *warehouse, int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(warehouse, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(warehouse);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		warehouse = ft_strjoin(warehouse, buffer);
	}
	return (warehouse);
}


char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	static char *warehouse;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	warehouse = read_cicle(warehouse, fd, buffer);
	if (!warehouse)
		return (NULL);
	line = ft_linetrim(warehouse);
	warehouse = ft_static_clean(warehouse, line);
	free(buffer);
	return (line);
}
