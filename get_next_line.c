/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:28 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/16 20:46:14 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/*
static memjoin(void *m1, void *m2)
{
  // to be implemented
}

static memdup(void *m1, void *m2, size_t n)
{
  // to be implemented
}
*/
static t_list	*rest_fd(const int fd, t_list **list)
{
	t_list	*lst;

	if (!(*list))
	{
		lst = ft_lstnew("", fd);
		ft_lstadd(list, lst);
		lst = *list;
		return (lst);
	}
	lst = *list;
	if ((int)lst->content_size == fd)
		return (lst);
	return (rest_fd(fd, &(lst->next)));
}

int				get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	char				*next;
	int					bytes_read;
	static t_list		*list;
	t_list				*lst;

	if (!line || fd < 0)
		return (-1);
	lst = rest_fd(fd, &list);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		buff[BUFF_SIZE] = 0;
		lst->content = ft_strjoin(lst->content, buff);
		next = ft_memchr(lst->content, '\n', ft_strlen(lst->content));
		if (next != NULL)
			break;
	}
	ft_memcpy(*line, lst->content, next - (char*)(lst->content));
	(lst->content) += (next - (char*)(lst->content));
	ft_strclr(lst->content);
	if (bytes_read == 0)
		return (0);
	return (1);
}
