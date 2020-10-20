/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:43:52 by trhee             #+#    #+#             */
/*   Updated: 2020/10/20 13:10:39 by trhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int					is_newline(char *buf)
{
	int				i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int					return_line(char **s, char **line, int len, int i)
{
	char			*tmp;

	if (i == -1)
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = 0;
		if (len == 0)
			return (0);
	}
	else
	{
		(*s)[i] = '\0';
		*line = ft_strdup(*s);
		tmp = ft_strdup(*s + i + 1);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
		{
			free(*s);
			*s = 0;
		}
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				len;
	static char		*s[OPEN_MAX];
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if ((is_newline(s[fd])) > -1)
			break ;
	}
	if (len < 0)
		return (-1);
	else if (len == 0 && (!s[fd]))
		*line = ft_strdup("");
	else
		return (return_line(&s[fd], line, len, is_newline(s[fd])));
	return (0);
}
