/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:37:15 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/28 11:47:32 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	if (!(*s))
	{
		if (c == '\0')
			return ((char*)s);
	}
	else if (ft_strrchr(s + 1, c))
		return (ft_strrchr(s + 1, c));
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
