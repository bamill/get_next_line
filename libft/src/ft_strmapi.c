/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:07:39 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 22:03:10 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*strmapito(char *dst, char const *s, \
							unsigned int i, char (*f)(unsigned int, char))
{
	if (!(*s))
		return ("\0");
	*dst = f(i, *s);
	*(dst + 1) = *strmapito(dst + 1, s + 1, i + 1, f);
	return (dst);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*st;

	if (!s)
		return (NULL);
	st = (char*)(malloc(ft_strlen(s) + 1));
	if (!st)
		return (NULL);
	strmapito(st, s, 0, f);
	return (st);
}
