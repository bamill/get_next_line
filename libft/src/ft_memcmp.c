/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:07:55 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 22:53:53 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	if ((*(unsigned char*)s1 == *(unsigned char*)s2) && n > 1)
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
