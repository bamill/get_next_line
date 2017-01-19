/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:28 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/18 20:27:56 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int				get_next_line(const int fd, char **line)
{
	int			bytes_read;
//	int		i;
	char		buff[BUFF_SIZE + 1];
	static char	**s;

	if (s && (s[0] != NULL))
	{
		ft_strcat(*line, s[0]);
		s++;
		if (s[0] != NULL)
			return (1);
	}
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		buff[BUFF_SIZE] = 0;
		s = ft_strsplit(buff, '\n');
		if (**line)
			ft_strcat(*line, s[0]);
		else
			ft_strcpy(*line, s[0]);
		if ((s + 1) == NULL)
			continue ;
		else
		{
			s++;
			return (1);
		}
	}
	return (0);
}
