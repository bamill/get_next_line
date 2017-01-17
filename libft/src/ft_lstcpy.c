/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:52:39 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 22:05:57 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list	*list;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (ft_lstnew(lst->content, lst->content_size));
	else
	{
		list = ft_lstnew(lst->content, lst->content_size);
		list->next = ft_lstcpy(lst->next);
		return (list);
	}
}
