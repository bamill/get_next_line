/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:48:08 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 02:39:55 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	result = (char*)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
	{
		*(result + i) = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		*(result + i) = *s2;
		s2++;
		i++;
	}
	*(result + i) = 0;
	return (result);
}
