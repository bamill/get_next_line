#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static int			line_len(char *s)
{
  char *tmp;

  if ((tmp = ft_strchr(s, '\n')))
    return (tmp - s);
  return (ft_strlen(s));
}

static t_list *fd_listuccino(t_list **rests, size_t fd)
{
  t_list				*lst;

  lst = *rests;
  while (lst)
	{
      if ((unsigned int)lst->content_size == fd)
        return (lst);
      lst = lst->next;
	}
  lst = ft_lstnew("\0", 2);
  lst->content_size = fd;
  ft_lstadd(rests, lst);
  lst = *rests;
  return (lst);
}

int	get_next_line(const int fd, char **line)
{
  static t_list *rests;
  char buff[BUFF_SIZE + 1];
  int bytes_read;
  char *s;
  t_list *lst;

  if (!line || fd < 0 || read(fd, buff, 0) < 0)
    return (-1);
  lst = fd_listuccino(&rests, fd);
  MEMCHK((*line = ft_strnew(1)));
  while ((bytes_read = read(fd, buff, BUFF_SIZE)))
	{
      buff[bytes_read] = '\0';
      MEMCHK((lst->content = ft_strjoin(lst->content, buff)));
      if (ft_strchr(buff, '\n'))
        break ;
	}
  if (!ft_strlen(lst->content) && bytes_read < BUFF_SIZE)
    return (0);
  *line = ft_strnew(line_len(lst->content));
  s = ft_strncpy(*line, lst->content, line_len(lst->content));
  (ft_strlen(s) < ft_strlen(lst->content))
    ? lst->content += (ft_strlen(s) + 1)
    : ft_strclr(lst->content);
  return (1);
}
