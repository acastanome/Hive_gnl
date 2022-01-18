/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:58 by acastano          #+#    #+#             */
/*   Updated: 2022/01/18 19:08:53 by acastano         ###   ########.fr       */
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
	size_t	chars_read;
//	size_t	**fd_position;

	if (fd < 0 || line == NULL)//if no file or no place to return possible read line
		return (-1);
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	chars_read = read(fd, buf, BUFF_SIZE);
	*line = buf;
	return (chars_read);
}
