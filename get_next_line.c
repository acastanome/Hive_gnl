/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:58 by acastano          #+#    #+#             */
/*   Updated: 2022/01/18 20:42:36 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>//read
#include <stdio.h>//printf
//# define BUFF_SIZE 42 defined in get_next_line.h

/*size_t	buff_size()
{

}*/

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	char	*temp;
	size_t	chars_read;
//	static int	fd_position;

	if (fd < 0 || line == NULL)//if no file or no place to return possible read line
		return (-1);
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
//	fd_position = fd;
//	chars_read = read(fd_position, buf, BUFF_SIZE);
	chars_read = read(fd, buf, BUFF_SIZE);
	temp = buf;
	while (read(fd, buf, BUFF_SIZE))
	{
		temp = ft_strjoin(temp + buf);	
		if (ft_strchr(temp, "\n"))
			break;
	}
//\n EOF
	*line = buf;
	return (chars_read);
}

/*
{


	{
		
	}
	}*/
