/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:48:17 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/19 00:06:59 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	char	nl[128];

	line = (char**)(malloc(sizeof(char*)));
	*line = nl;
	if (argc < 2)
		printf("usage: %s: file\n", argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, line) > 0)
		printf("%s\n", *line);
	return (0);
}
