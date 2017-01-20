/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:28 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/19 15:59:25 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int				get_next_line(const int fd, char **line)
{
	int			bytes_read;
	char		buff[BUFF_SIZE + 1];
	char		*nl;
	char		*tmp;
	static char	*s = NULL;

	if (!line || !(*line) || fd == -1 || !((*line = ft_strnew(0))))
		return (-1);
	if (s)
	{
		if (*s == '\n')
			s++;
		nl = ft_strchr(s, '\n');
		tmp = nl ? ft_strsub(s, 0, nl - s + 1) : s;
		*line = ft_strjoin(*line, tmp);
		nl ? s += (nl - s) : ft_strdel(&s);
	}
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		buff[BUFF_SIZE] = 0;
		nl = ft_strchr(buff, '\n');
		if (nl)
		{
			tmp = ft_strsub(buff, 0, nl - buff + 1);
			*line = ft_strjoin(*line, tmp);
			ft_strclr(tmp);
			if (ft_strlen(nl) > 1)
				s = ft_strdup(nl + 1);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
	}
	*line = ft_strjoin(*line, buff);
	return (0);
}
