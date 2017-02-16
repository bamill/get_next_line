#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int		r_lookup(const int fd, char **line, char rests[MAX_FD][BUFF_SIZE + 1])
{
  int	count;
  int	offset;
  _Bool found_nl;

  count = 0;
  while ((rests[fd][count] != 0) && (rests[fd][count] != '\n')) {
    *(*line + count) = rests[fd][count];
    count++;
    }
  *(*line + count) = 0;
  found_nl = (rests[fd][count] == '\n') ? 1 : 0;
  if (found_nl) {
    offset = count;
    rests[fd][offset] = 0;
    while (offset < (BUFF_SIZE)) {
      rests[fd][offset - count] = rests[fd][offset + 1];
      rests[fd][offset - BUFF_SIZE * -1] = 0;
      offset++;
    }
  }
  else {
    ft_bzero(rests[fd], BUFF_SIZE + 1);
  }
  return (found_nl ? -1 : count);
}

int				get_next_line(const int fd, char **line)
{
  static char	rests[MAX_FD][BUFF_SIZE + 1];
  char			buff[BUFF_SIZE + 1];
  int			i;
  int			j;
  int			bytes_read;

  if (!line || fd < 0 || (read(fd, buff, 0) < 0))
    return (-1);
  //ft_bzero(*line, 2048);
  i = r_lookup(fd, line, rests);
  if (i == -1)
    return (1);
  while ((bytes_read = read(fd, buff, BUFF_SIZE))) {
    j = 0;
	while (j < BUFF_SIZE) {
      if (buff[j] != '\n') {
        *(*line + i) = buff[j];
        i++;
        j++;
      }
      else
        {
          *(*line + i) = 0;
          i = 0;
          j++;
          while (j < BUFF_SIZE) {
            rests[fd][i] = buff[j];
            j++;
            i++;
      		}
          ft_bzero(buff, BUFF_SIZE + 1);
          return (1);
        }
    }
    ft_bzero(buff, BUFF_SIZE + 1);
  }
  j = 0;
  while (j < BUFF_SIZE) {
    *(*line + i) = buff[j];
    i++;
    j++;
  }
  return (0);
}
