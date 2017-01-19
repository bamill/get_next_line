/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:28 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/18 23:24:13 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <strings.h>

int				get_next_line(const int fd, char **line)
{
	int			bytes_read;
	int			i;
	char		buff[BUFF_SIZE + 1];
	static char	*s = NULL;

	if (s && ft_strlen(s) > 1)
		strncat(*line, s, ft_strlen(s));
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			if (*line == NULL)
				strncpy(*line, buff, i);
			else
				strncat(*line, buff, i);
			strtok(buff, "\n");
			s = strtok(NULL, "\n");
			return (1);
		}
		else if (buff[i] == 0)
		{
			if (*line == NULL)
				strncpy(*line, buff, i);
			else
				strncat(*line, buff, i);
			s = NULL;
			return (0);
		}
		else
			strcat(*line, buff);
	}
	return (-1);
}
