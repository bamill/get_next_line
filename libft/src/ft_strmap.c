/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:57:52 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 22:04:27 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*strmapto(char *dst, char const *s, char (*f)(char))
{
	if (!(*s))
		return ("\0");
	*dst = f(*s);
	*(dst + 1) = *strmapto(dst + 1, s + 1, f);
	return (dst);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*st;

	if (!s)
		return (NULL);
	st = (char*)(malloc(ft_strlen(s) + 1));
	if (st == NULL)
		return (NULL);
	st = strmapto(st, s, f);
	return (st);
}
