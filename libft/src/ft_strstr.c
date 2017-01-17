/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:00 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 21:51:14 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;
	size_t	i;

	if (!(*little))
		return ((char*)big);
	len = ft_strlen(little);
	i = 0;
	while (*big)
	{
		while (*big == *little && (i < len))
		{
			little++;
			big++;
			i++;
		}
		if (i == len)
			return ((char*)(big - i));
		little -= i;
		big -= i;
		i = 0;
		big++;
	}
	return (NULL);
}
