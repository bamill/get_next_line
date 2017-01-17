/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:53:20 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/29 16:02:26 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char*)s;
	while (i < n)
	{
		if (*(st + i) == (unsigned char)c)
			return (st + i);
		i++;
	}
	return (NULL);
}
