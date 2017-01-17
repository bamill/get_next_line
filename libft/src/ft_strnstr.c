/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:12:25 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/04 12:46:43 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;

	slen = ft_strlen(l);
	if (!(*l))
		return ((char*)b);
	j = 0;
	while (*b && j < len)
	{
		i = 0;
		while (*b == *l && (i < slen) && (j < len))
		{
			l++;
			b++;
			i++;
			j++;
		}
		if (i == slen)
			return ((char*)(b - i));
		l -= i;
		b -= (i - 1);
		j -= (i - 1);
	}
	return (NULL);
}
