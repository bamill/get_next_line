/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:10:21 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/28 17:14:01 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	ptr_d;

	if (!(*s2))
		return (s1);
	ptr_d = 0;
	while (*s1)
	{
		s1++;
		ptr_d++;
	}
	while (*s2 && n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		ptr_d++;
		n--;
	}
	if (ptr_d != 0)
		*s1 = '\0';
	return (s1 - ptr_d);
}
