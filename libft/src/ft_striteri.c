/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:44:57 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/04 12:35:23 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		ft_striteri_the_ultimate(char *s, unsigned int i,\
										void (*f)(unsigned int, char *))
{
	if (!(*s))
		return ;
	f(i, s);
	ft_striteri_the_ultimate(s + 1, i + 1, f);
}

void			ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (!s || !f)
		return ;
	return (ft_striteri_the_ultimate(s, 0, f));
}
