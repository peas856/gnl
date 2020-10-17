/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:44:19 by trhee             #+#    #+#             */
/*   Updated: 2020/10/17 17:13:07 by trhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int					is_newline(char *buf);
int					return_line(char **s, char **line, int len, int i);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
