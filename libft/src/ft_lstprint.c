/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:17:09 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/05 23:36:31 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstprint(t_list *lst, void (*f)(void*))
{
	if (!lst)
		return ;
	f(lst->content);
	ft_putstr("->");
	if (!(lst->next))
	{
		ft_putchar('\n');
		return ;
	}
	return (ft_lstprint(lst->next, f));
}
