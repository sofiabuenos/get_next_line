/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:03:28 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/15 16:47:37 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
char	*get_next_line(int fd);

// **utils** 
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_linetrim(char *warehouse);
char	*ft_static_clean(char *warehouse, char *linetoprint);
/* int	cicle(char *warehouse, int fd, ssize_t bytes_read, char *buffer); */

#endif