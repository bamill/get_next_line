/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:24:44 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 23:07:18 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (*s1 == *s2 && *s1 && n > 0)
		return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
	if (*s1 != *s2)
		return (0);
	return (1);
}
