/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:15:02 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 21:50:24 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		n;
	size_t		dst_len;

	s = src;
	d = dst;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dst_len = d - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
