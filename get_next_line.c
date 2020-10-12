/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:43:52 by trhee             #+#    #+#             */
/*   Updated: 2020/10/10 19:32:21 by trhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				is_newline(char *buf)
{
	int			i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}



int				get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE];
	char		*line;
	int			read_len;
	char		*read_line[OPNE_MAX];
	int			split_idx;

	if (fd < 0 || !line)
		return (-1);
	while ((read_len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		read_line[fd] = ft_strjoin(read_line[fd], buf);
		if ((split_idx = is_newline(read_line[fd])))
			return (split_line(read_line[fd], line, split_idx));
	}

}
