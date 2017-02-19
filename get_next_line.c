/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:33:03 by bmiller           #+#    #+#             */
/*   Updated: 2017/02/19 12:01:24 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
** ft_strnjoin: takes two null-terminated strings and a size and   **
** returns the result of joining the second up to size characters  **
** onto the first and null terminating the result                  **
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*/

static char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char		*s;
	int			nbr;
	char		*st;

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

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
** ft_strndup: takes a null-terminated string and a size (int) and **
** returns a copy of the string up to that many characters         **
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*/

static char		*ft_strndup(const char *s, int n)
{
	char		*s1;
	int			i;

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

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
** join_free: a wrapper function for ft_strnjoin that takes the    **
** same parameters and additionally frees the first string passed  **
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*/

static char		*join_free(char *s1, char *s2, size_t n)
{
	char		*tmp;

	tmp = s1;
	s1 = ft_strnjoin(s1, s2, n);
	free(tmp);
	return (s1);
}

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
** fd_listuccino: takes a pointer to a list pointer and a file     **
** descripter and returns a pointer to the list link containing    **
** a string read and joined by gnl with the file descriptor        **
** as the content_size attribute                                   **
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*/

static t_list	*fd_listuccino(t_list **rests, size_t fd)
{
	t_list		*lst;

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

/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
** get_next_line: takes a file descriptor and a pointer to a       **
** string and returns an integer representing an exit status,      **
** being either 1, 0, -1 corresponding to whether a line was read  **
** the EOF was reached, or an error occurred, respectively.        **
** First, input is validated and a read check is performed on the  **
** file descriptor of 0 bytes to check if it is readable.  Then a  **
** temporary list variable is assigned to our static list variabl  **
** used to store the rest of the buffer between function calls.    **
** The static list variable is then assigned to the return of the  **
** fd_listuccino lookup/creation function.  We then loop until     **
** we either reach a newline or EOF, reading into our buffer and   **
** joining the results onto the static variable string each read,  **
** wrapping that with the MEMCHK macro which returns -1 in the     **
** case of a failed assignment.  We then use the b_r variable      **
** as an index, assigning it to 0 and the looping through          **
** the static list pointer variable until we either reach a null   **
** terminator or a newline, incrementing it at each iteration.     **
** We use this variable to pass to ft_strndup along with the       **
** content of the static list variable's link we filled just       **
** previously, to set line equal to the appropriate length         **
** string duplicate.  We then increment b_r if we reached a        **
** new line, or leave as is in the case of a null terminator.      **
** We store the current static list pointer content attribute      **
** in a temporary char pointer and strdup the the point we reache  **
** into the list content, subsequently freeing the pointer we jus  **
** saved.  Finally, we set the static back to the initial link we  **
** saved at the beginning, and return 1 or 0 depending on if we    **
** looped through the static and read bytes or not.                **
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	char			buff[BUFF_SIZE + 1];
	int				b_r;
	char			*s;
	t_list			*lst;

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	lst = l;
	l = fd_listuccino(&lst, fd);
	while (!ft_strchr(l->content, '\n') && (b_r = read(fd, buff, BUFF_SIZE)))
		MEMCHK((l->content = join_free(l->content, buff, b_r)));
	b_r = 0;
	while (((char*)l->content)[b_r] && (((char*)l->content)[b_r]) != '\n')
		++b_r;
	*line = ft_strndup(l->content, b_r);
	b_r = ((char*)l->content)[b_r] == '\n' ? b_r + 1 : b_r;
	s = l->content;
	l->content = ft_strdup(l->content + b_r);
	free(s);
	l = lst;
	return (b_r ? 1 : 0);
}
