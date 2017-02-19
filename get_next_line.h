/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:40:51 by bmiller           #+#    #+#             */
/*   Updated: 2017/02/19 12:02:24 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MEMCHK(m) if (!m) return (-1);
# include <stdlib.h>
# include "libft.h"

int				get_next_line(const int fd, char **line);

#endif
