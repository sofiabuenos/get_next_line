/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:33 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/07 12:59:10 by sbueno-s         ###   ########.fr       */
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
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
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
	line = malloc(len[1] - len[0] +1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len[1] - len[0])
	{
		line[i] = warehouse[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* int	main(void)
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
	printf("%s", res);
} */

/* int	main(void)
{
	char	*warehouse = "Fly me to the moon\n let me";
	char	*line = ft_linetrim(warehouse, '\n');
	printf("%s", line);
	return (0);
} */