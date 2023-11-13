/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:33 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/13 16:00:27 by sbueno-s         ###   ########.fr       */
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
	/* if (!warehouse)
	{
		warehouse = malloc(1);
		warehouse[0] = '\0';
	} */
	while (i < len[0])
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

char	*ft_linetrim(char *aux)
{
	int		i;
	char	*str;

	i = 0;
	if (!aux[i])
		return (NULL);
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] == '\0')
		str = (char *)malloc(sizeof(char) * (i + 1));
	else
		str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (aux[i] && aux[i] != '\n')
	{
		str[i] = aux[i];
		i++;
	}
	if (aux[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}



char	*ft_static_clean(char *warehouse, char *linetoprint)
{
	char	*newhouse;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(warehouse) - ft_strlen(linetoprint);
	if (len == 0)
	{
		free(warehouse);
		return (NULL);
	}
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

/* int	main(void)
{
	char	*warehouse = "Fly me to the moon\nLet me";
	char	*linetoprint = "Fly me to the moon";
	char	*newhouse = ft_static_clean(warehouse, linetoprint);
	printf("%s", newhouse);
} */