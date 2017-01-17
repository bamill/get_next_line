/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:57:59 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/04 15:32:55 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	is_ws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	if (!(*s))
		return (ft_strsub(s, 0, 0));
	if (is_ws(*s))
		return (ft_strtrim(s + 1));
	if (is_ws(*(s + (ft_strlen(s)) - 1)))
		return (ft_strtrim((char const*)ft_strsub(s, 0, ft_strlen(s) - 1)));
	return (ft_strsub(s, 0, ft_strlen(s)));
}
