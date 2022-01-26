/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:58 by acastano          #+#    #+#             */
/*   Updated: 2022/01/26 18:36:38 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>//read
#include <stdlib.h>//free
#include <stdio.h>
# define FD_MAX 4096

//If a \n is found in rem, mallocs line to be rem before \n, and rem after \n
//Return values: 0 if no \n, 1 if \n and -1 upon error(when malloc)
int	ft_is_newline(char **rem, char ***line)
{
	char	*location;
	char	*temp;

	temp = NULL;
	location = ft_strchr(*rem, '\n');
	if (location)
		{
			**line = ft_strsub(*rem, 0, (location - *rem));
			if (!(**line))
				return (-1);
			if (*(location + 1) == '\0')
			{
				free(*rem);
				*rem = NULL;
			}
			else
			{
				temp = ft_strdup(location + 1);
				free(*rem);
				*rem = temp;
			}
			return (1);
		}
	return (0);
}

int	ft_get_text(char **rem, const int fd)//is there a rem or can you get one?
{
	char	*buf;
	ssize_t		chars_read;
	char	*temp;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	chars_read = read(fd, buf, BUFF_SIZE);
	if (chars_read > 0)
	{
		if (*rem == NULL)
			*rem = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*rem, buf);
			free(*rem);
			*rem = temp;
		}
		free(buf);
		if (!(*rem))
			return (-1);
	}
	return (chars_read);
/*
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	chars_read = read(fd, buf, BUFF_SIZE);
	if (chars_read == 0)
		return (0);
	if (chars_read < 0)
		return (-1);
	if (*rem == NULL)//if chars_read > 0
		*rem = ft_strdup(buf);
	else//also chars_read > 0
	{
		temp = ft_strjoin(*rem, buf);
		free(*rem);
		*rem = temp;
	}
	free(buf);
	if (!(*rem))
		return (-1);
	return (1);
*/
}

int	ft_clean(char **string)
{
	ft_strdel(&(*string));
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_tracker[FD_MAX + 1];
	ssize_t	chars_read;
	int	found_line;

	if (fd < 0 || line == NULL || fd >= FD_MAX || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	chars_read = 0;
	found_line = 0;
	while (*line == NULL)//until we find a line or EOF
	{
		if (fd_tracker[fd] != NULL)//if something saved from this file
		{
			found_line = ft_is_newline(&fd_tracker[fd], &line);
			if (found_line == 1)
				return (1);
			if (found_line < 0)
				break;
		}
		chars_read = ft_get_text(&fd_tracker[fd], fd);//reading
		if (chars_read <= 0)
			break;
	}
	if (found_line < 0 || chars_read < 0)//sthg went wrong
		return (ft_clean(&fd_tracker[fd]));
	if ((fd_tracker[fd] != NULL) && (ft_strlen(fd_tracker[fd]) != 0))//sthg saved
	{
		*line = ft_strdup(fd_tracker[fd]);
		if (!(*line))
			return (ft_clean(&fd_tracker[fd]));
		found_line = 1;
	}
	ft_clean(&fd_tracker[fd]);
	return (found_line);
}
