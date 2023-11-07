/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/07 15:49:28 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*linetoprint;
	static char *warehouse;
	ssize_t	bytes_read;

	warehouse = "";
	bytes_read = 1;
	buffer = malloc(READING_CHUNK + 1);
	if (buffer == NULL)
	{
		printf("memory allocation issue");
		return (NULL);
	}
	while (bytes_read > 0 && ft_strchr(warehouse, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, READING_CHUNK);
		// colocar condicao de erro aqui tbm 
		buffer[bytes_read] = '\0';
		warehouse = ft_strjoin(warehouse, buffer);
	}
	if (bytes_read == -1)
	{
		printf("oops, can't read anything");
		free(buffer);
		free(warehouse);
		return (NULL);
	}
	linetoprint = ft_linetrim(warehouse, '\n');
	free(buffer);
	return (linetoprint);
}

int	main(void)
{
	char *line;
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("the file is not opening :/");
		return (-1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return(0);
}

