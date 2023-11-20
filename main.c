/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:23:15 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/18 17:46:02 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	main(void)
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
} */

/* #include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd[argc-1];

	for (int i = 1; i < argc; i++)
	{
		fd[i - 1] = open(argv[i], O_RDONLY);
		if (fd[i -1] == -1)
		{
			printf("the file %s is not opening :/\n", argv[i]);
			continue;
		}	
		line = get_next_line(fd[i - 1]);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd[i - 1]);
		}
		close(fd[i - 1]);
		printf("\n");
	}
	return(0);
} */
