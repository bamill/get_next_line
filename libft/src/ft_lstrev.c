/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 06:48:23 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 22:26:37 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstrev(t_list *lst)
{
	t_list	*list;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (ft_lstnew(lst->content, lst->content_size));
	else
	{
		list = ft_lstnew(ft_lst_last(lst), sizeof(ft_lst_last(lst)));
		list->next = ft_lstrev(ft_lst_butlast(lst));
		return (list);
	}
}
