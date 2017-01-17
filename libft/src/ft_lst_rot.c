/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:24:07 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 21:50:57 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_rot(t_list *lst, int i)
{
	t_list *list;
	t_list *l;

	if (!lst)
		return (NULL);
	if (i == 0)
		return (lst);
	list = ft_lstnew(lst->content, lst->content_size);
	l = ft_lstrest(lst);
	ft_lstadd(&l, list);
	return (ft_lst_rot(list, i - 1));
}
