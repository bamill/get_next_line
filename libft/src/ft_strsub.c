/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:35:08 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 21:57:51 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;

	if (!s)
		return (NULL);
	st = (char*)(malloc(len + 1));
	if (!st)
		return (NULL);
	i = 0;
	len += (size_t)start;
	while (start < (unsigned int)len)
	{
		*(st + i) = *(s + start);
		start++;
		i++;
	}
	*(st + i) = '\0';
	return (st);
}
