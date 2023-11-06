/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:33 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/06 18:14:38 by sbueno-s         ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	size_t	len[2];
	size_t	i;

	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	joint = malloc(sizeof(char)* (len[0] + len[1] + 1));
	if (!joint)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	while (i < len[0] + len[1])
	{
		joint[i] = s2[i - len[0]];
		i++;
	}
	joint[i] = '\0';
	return (joint);
}

/* int	main(void)
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
	printf("%s", res);
} */