/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:30:09 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/02 21:32:20 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s || !(*s))
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return ;
}
