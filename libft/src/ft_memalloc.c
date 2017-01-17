/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:48:14 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/29 16:57:26 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)(malloc(size));
	if (mem == NULL)
		return (NULL);
	while (size > 0)
	{
		*(mem + (size - 1)) = 0;
		size--;
	}
	return ((void*)mem);
}
