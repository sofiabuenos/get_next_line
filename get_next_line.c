/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/13 17:37:20 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*linetoprint;
	static char *warehouse;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (bytes_read > 0 && ft_strchr(warehouse, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(warehouse);
			warehouse = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		warehouse = ft_strjoin(warehouse, buffer);
	}
	linetoprint = ft_linetrim(warehouse);
	warehouse = ft_static_clean(warehouse, linetoprint);
	free(buffer);
	return (linetoprint);
}
