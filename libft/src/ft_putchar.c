/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:10:45 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 21:41:01 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	int				result;

	if (c < 0x80)
		write(1, &c, 1);
	else if (c < 0x800)
	{
		result = ((c >> 6) | 0xC0) + (((c & 0x3F) | 0x80) << 8);
		write(1, &result, 2);
	}
	else if (c < 0x10000)
	{
		result = ((c >> 12) | 0xE0) + ((((c >> 6) & 0x3F) | 0x80) << 8);
		result += ((c & 0x3F) | 0x80) << 16;
		write(1, &result, 3);
	}
	else if (c < 0x110000)
	{
		result = ((c >> 18) | 0xF0) + ((((c >> 12) & 0x3F) | 0x80) << 8);
		result += (((c >> 6) & 0x3F) | 0x80) << 16;
		result += ((c & 0x3F) | 0x80) << 24;
		write(1, &result, 4);
	}
	return ;
}
