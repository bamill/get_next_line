/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:40:51 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/14 20:55:33 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# define BUFF_SIZE 32
# include <stdlib.h>
# include "./libft/includes/libft.h"

int				get_next_line(const int fd, char **line);

#endif
