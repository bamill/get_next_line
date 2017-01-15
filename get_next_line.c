#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static memjoin(void *m1, void *m2)
{
  // to be implemented
}

static memdup(void *m1, void *m2, size_t n)
{
  // to be implemented
}

static t_list	*rest_fd(const int fd, t_list **list)
{
	t_list	*lst;

	if (!list || !(*list))
	  return (NULL);
	lst = *list;
	if ((int)lst->content_size == fd)
	  return (lst);
	else if (lst->next == NULL)
	  {
	    lst = ft_lstnew("\0", fd);
	    ft_lstadd(list, lst);
	    lst = *list;
	  }
	return (rest_fd(fd, &(lst->next)));
}

int		get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int				bytes_read;
	int				i;
	static t_list			*list;
	t_list				*lst;

	if ((!line || fd < 0 || read(fd, buff, 0) < 0 || \
	     !(*line = ft_strnew(1))))
		return (-1);
	lst = rest_fd(fd, &list);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
		buff[bytes_read] = '\0';
		if (!(lst->content = ft_strjoin(lst->content, buff)))
		  return (-1);
		if ((i = (buff - ft_memchr(buff, '\n', BUFF_SIZE))) != buff)
		  break;
	}
	if (lst->content == NULL && (bytes_read < BUFF_SIZE))
		return (0);
	ft_memccpy(*line, buff, '\n', i);
	if (i < (int)sizeof(lst->content) && lst->content != NULL)
	  lst->content += (i + 1);
	else
	  ft_strclr(lst->content);
	return (1);
}
