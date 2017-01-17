/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:17:51 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 22:38:13 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*s1 && *s1 == *s2 && n > 1)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
