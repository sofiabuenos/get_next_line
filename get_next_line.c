/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/06 15:32:08 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	static ssize_t	bytes_read;

	buffer = malloc(READING_CHUNK); // duvida 1
	if (buffer == NULL)
	{
		printf("memory allocation issue");
		return (NULL);
	}
	bytes_read = read(fd, buffer, READING_CHUNK -1);
	if (bytes_read == -1)
	{
		printf("oops, can't read anything");
		free (buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("the file is not opening :/");
		return (-1);
	}
	char *line = get_next_line(fd);
	if (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}

// duvida 1: my buffer size must be at least as long as my reading chunk, right?
// should I consider the null character as well?