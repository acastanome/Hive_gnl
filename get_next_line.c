/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:58 by acastano          #+#    #+#             */
/*   Updated: 2022/01/21 20:16:09 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>//read
#include <stdlib.h>//free
# define FD_MAX 4096

int	ft_gnl(char **rem, char ***line)//find line in rem
{
	char	*location;

	location = ft_strchr(*rem, '\n');
	if (location)
		{
			**line = ft_strsub(*rem, 0, (location - *rem));// until \n;
			*rem = location + 1;// after \n;
			return (1);
		}
	return (0);
}

int	ft_remainder(char **rem, const int fd)//is there a rem or can you get one?
{
	char	*buf;

	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);//should return somewhere this
	if (read(fd, buf, BUFF_SIZE) == 0)
		return (0);
	if (*rem == NULL)
		*rem = ft_strdup(buf);
	else
		*rem = ft_strjoin(*rem, buf);
	free(buf);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_tracker[FD_MAX + 1];

	if (fd < 0 || line == NULL || fd > FD_MAX || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	while (*line == NULL)//until we find a line
	{
		if (fd_tracker[fd] != NULL)//if something saved from this file
		{
			if (ft_gnl(&fd_tracker[fd], &line) == 1)//is there a nl?
				return (1);
		}
		if (ft_remainder(&fd_tracker[fd], fd) == 0)//read and get rem, or EOF return 0
		{
//what if no nl but EOF
			return (0);
		}
	}
	return (0);
}
