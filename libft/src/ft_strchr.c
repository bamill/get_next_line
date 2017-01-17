/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:33:20 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/28 11:29:05 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (!(*s))
	{
		if (c == '\0')
			return ((char*)s);
		return (NULL);
	}
	else if (*s == c)
		return ((char*)s);
	else
		return (ft_strchr(s + 1, c));
}
