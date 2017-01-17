/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:13:06 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 21:47:33 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin, void *d, int (*cmp)())
{
	t_list	*list;

	if (!begin || !(*begin))
		return ;
	if (!cmp((*begin)->content, d))
	{
		list = *begin;
		*begin = (*begin)->next;
		free(list);
		ft_list_remove_if(begin, d, cmp);
	}
	else
		ft_list_remove_if(&(*begin)->next, d, cmp);
	return ;
}
