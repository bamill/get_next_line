/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:19:19 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/29 17:26:31 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	size++;
	s = (char*)(malloc(size));
	if (s == NULL)
		return (NULL);
	while (size > 0)
	{
		*(s + (size - 1)) = '\0';
		size--;
	}
	return (s);
}
