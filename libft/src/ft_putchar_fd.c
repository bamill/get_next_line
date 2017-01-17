/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:22:39 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 21:42:03 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(int c, int fd)
{
	int				result;

	if (c < 0x80)
		write(fd, &c, 1);
	else if (c < 0x800)
	{
		result = ((c >> 6) | 0xC0) + (((c & 0x3F) | 0x80) << 8);
		write(fd, &result, 2);
	}
	else if (c < 0x10000)
	{
		result = ((c >> 12) | 0xE0) + ((((c >> 6) & 0x3F) | 0x80) << 8);
		result += ((c & 0x3F) | 0x80) << 16;
		write(fd, &result, 3);
	}
	else if (c < 0x110000)
	{
		result = ((c >> 18) | 0xF0) + ((((c >> 12) & 0x3F) | 0x80) << 8);
		result += (((c >> 6) & 0x3F) | 0x80) << 16;
		result += ((c & 0x3F) | 0x80) << 24;
		write(fd, &result, 4);
	}
	return ;
}
