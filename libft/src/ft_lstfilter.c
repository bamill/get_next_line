/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 03:46:38 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 18:50:32 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfilter(t_list *lst, int (*f)(void *))
{
	t_list	*list;

	if (!lst)
		return (NULL);
	else
	{
		if (f(lst->content))
		{
			list = ft_lstnew(lst->content, lst->content_size);
			list->next = ft_lstfilter(lst->next, f);
		}
		else
			return (ft_lstfilter(lst->next, f));
		return (list);
	}
}
