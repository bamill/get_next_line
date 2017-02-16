#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static void ins(t_list *rests, const int fd, char *buff)
{
  if (!rests) {
    rests = ft_lstnew(buff, ft_strlen(buff));
    rests->content_size = (unsigned int)fd;
    return ;
  }
  if (rests->content_size == (unsigned int)fd) {
    rests->content = buff;
    return ;
  }
  if (!(rests->next)) {
    rests->next = ft_lstnew(buff, ft_strlen(buff));
    rests->next->content_size = (unsigned int)fd;
    return ;
  }
  ins(rests->next, fd, buff);
}

static char	*retrieve(t_list *rests, const int fd)
{
  char *tmp;
  char *result;

  if (!rests)
    return (NULL);
  else if (rests->content_size != (unsigned int)fd || rests->content == NULL)
    return (retrieve(rests->next, fd));
  if ((tmp = ft_strchr(rests->content, '\n'))) {
    tmp++;
    result = ft_strsub(rests->content, 0, tmp - (char*)(rests->content));
    ins(rests, fd, tmp);
    return (result);
  }
  result = ft_strdup(rests->content);
  ins(rests, fd, NULL);
  return (result);
}

static int	ret_line(t_list *rests, const int fd, char **line)
{
  char *tmp;
  char buff[BUFF_SIZE + 1];

  if ((tmp = retrieve(rests, fd)))
    {
      if (ft_strchr(tmp, '\n')) {
        *line = ft_strtrim(tmp);
        ft_strdel(&tmp);
        return (1);
      }
      *line = tmp;
    }
  while ((read(fd, buff, BUFF_SIZE)))
    {
      if (ft_strchr(buff, '\n')) {
        ins(rests, fd, buff);
        return (ret_line(rests, fd, line));
      }
      ft_strjoin(*line, buff);
    }
  if (buff[0]) {
    ins(rests, fd, buff);
    return (ret_line(rests, fd, line));
  }
  return (0);
}

int		get_next_line(const int fd, char **line)
{
  static t_list		*rests;
  char buff[BUFF_SIZE + 1];

  if (!line || fd < 0 || read(fd, buff, 0) < 0)
    return (-1);
  return (ret_line(rests, fd, line));
}
