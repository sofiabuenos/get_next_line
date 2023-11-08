/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:08 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/08 16:45:40 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s[i]);
	return (NULL);
}
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *warehouse, char *buffer)
{
	char	*joint;
	size_t	len[2];
	size_t	i;

	len[0] = ft_strlen(warehouse);
	len[1] = ft_strlen(buffer);
	joint = malloc(sizeof(char)* (len[0] + len[1] + 1));
	if (!joint)
		return (NULL);
	i = 0;
	if (!warehouse)
	{
		warehouse = malloc(1);
		warehouse[0] = '\0';
	}
	while (warehouse[i])
	{
		joint[i] = warehouse[i];
		i++;
	}
	while (i < len[0] + len[1])
	{
		joint[i] = buffer[i - len[0]];
		i++;
	}
	free(warehouse);
	joint[i] = '\0';
	return (joint);
}
char	*ft_linetrim(char *warehouse, int c)
{
	char	*contains_newline;
	char	*line;
	size_t	len[2];
	size_t	i;

	contains_newline = ft_strchr(warehouse, c);
	len[0] = ft_strlen(contains_newline);
	len[1] = ft_strlen(warehouse);
	line = malloc(len[1] - len[0] + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= len[1] - len[0])
	{
		line[i] = warehouse[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_static_clean(char *warehouse, char *linetoprint)
{
	char	*newhouse;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(warehouse) - ft_strlen(linetoprint);
	i = 0;
	newhouse = malloc(len + 1);
	if (!newhouse)
		return (NULL);
	while (warehouse[i] != '\n' && warehouse[i] != '\0')
		i++;
	j = 0;
	i++;
	while (warehouse[i]!= '\0')
	{
		newhouse[j] = warehouse[i];
		j++;
		i++;
	}
	newhouse[j] = '\0';
	free(warehouse);
	return (newhouse);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*linetoprint;
	static char *warehouse;
	ssize_t	bytes_read;

	//warehouse = "";
	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		printf("memory allocation issue");
		return (NULL);
	}
	while (bytes_read > 0 && ft_strchr(warehouse, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			printf("oops, can't read anything");
			free(buffer);
			free(warehouse);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		warehouse = ft_strjoin(warehouse, buffer);
	}
	linetoprint = ft_linetrim(warehouse, '\n');
	warehouse = ft_static_clean(warehouse, linetoprint);
	free(buffer);
	return (linetoprint);
}

int	main(void)
{
	char	*line;
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("the file is not opening :/");
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return(0);
}

