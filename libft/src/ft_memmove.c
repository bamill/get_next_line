/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:18:13 by bmiller           #+#    #+#             */
/*   Updated: 2016/11/29 12:22:04 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*tmp;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	tmp = (unsigned char*)(malloc(len));
	if (tmp == NULL)
		return (dst);
	ft_memcpy(tmp, s, len);
	ft_memcpy(d, tmp, len);
	free(tmp);
	return (dst);
}
