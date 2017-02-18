#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>


static char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
  char	*s;
  int	nbr;
  char	*st;

  nbr = ft_strlen(s1) + ++n;
  s = ft_strnew(nbr);
  st = s;
  while (*s1)
    *s++ = *s1++;
  while (*s2 && --n > 0)
    *s++ = *s2++;
  *s = '\0';
  return (s - (s - st));
}

static char		*ft_strndup(const char *s, int n)
{
  char		*s1;
  int		i;

  i = 0;
  s1 = (char*)malloc(sizeof(char) * n + 1);
  if (!s1)
    return (NULL);
  while (s[i] && i < n)
	{
      s1[i] = s[i];
      i++;
	}
  s1[i] = 0;
  return (s1);
}

static char			*join_free(char *s1, char *s2, size_t n)
{
  	char	*tmp;

    tmp = s1;
    s1 = ft_strnjoin(s1, s2, n);
    free(tmp);
	return (s1);
}

static t_list *fd_listuccino(t_list **rests, size_t fd)
{
  t_list				*lst;

  lst = *rests;
  if (lst)
    {
      while (lst)
        {
          if ((size_t)lst->content_size == fd)
            return (lst);
          lst = lst->next;
        }
    }
  lst = ft_lstnew("\0", 1);
  lst->content_size = fd;
  ft_lstadd(rests, lst);
  return (lst);
}

int	get_next_line(const int fd, char **line)
{
  static t_list *rests = NULL;
  char buff[BUFF_SIZE + 1];
  int b_r;
  char *s;
  t_list *lst;

  if (!line || fd < 0 || read(fd, buff, 0) < 0)
    return (-1);
  lst = rests;
  rests = fd_listuccino(&lst, fd);
  while (!ft_strchr(rests->content, '\n') && (b_r = read(fd, buff, BUFF_SIZE)))
    MEMCHK((rests->content = join_free(rests->content, buff, b_r)));
  b_r = 0;
  while (((char*)rests->content)[b_r] && (((char*)rests->content)[b_r]) != '\n')
    ++b_r;
  *line = ft_strndup(rests->content, b_r);
  b_r = ((char*)rests->content)[b_r] == '\n' ? b_r + 1 : b_r;
  s = rests->content;
  rests->content = ft_strdup(rests->content + b_r);
  free(s);
  rests = lst;
  return (b_r ? 1 : 0);
}
