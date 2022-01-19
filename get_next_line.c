/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:58 by acastano          #+#    #+#             */
/*   Updated: 2022/01/19 19:11:02 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>//read
#include <stdio.h>//printf
#include <stdlib.h>//free
//# define BUFF_SIZE 42 defined in get_next_line.h
# define FD_SIZE 4096

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	char	*temp;
	size_t	bytes_read;
	int	newline;
	static char	*fd_tracker[FD_SIZE];

	newline = 1;
	if (fd < 0 || line == NULL)//if no file or no place to return possible read line
		return (-1);

	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFF_SIZE);
	temp = ft_strdup(buf);
	if (!temp)
	{
		free(buf);
		return(-1);
	}
	while (read(fd, buf, BUFF_SIZE))
	{
		if (ft_strchr(temp, '\n'))
		{
			newline = 0;
			break;
		}
		temp = ft_strjoin(temp, buf);
		bytes_read = ft_strlen(temp);
//		if (ft_strchr(temp, '\n'))
//			break;
}
//\n EOF
	if (newline)//get string ending before the \n
	{
		ft_memccpy(fd_tracker[fd], temp, '\n', bytes_read);
	}
	*line = temp;
	return ((bytes_read == 0) ? 0 : 1);
}
