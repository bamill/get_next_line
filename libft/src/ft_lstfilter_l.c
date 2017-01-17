/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:49:36 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/07 19:13:42 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfilter_l(t_list *lst, int (*f)(t_list *))
{
	t_list	*list;

	if (!lst)
		return (NULL);
	else
	{
		if (f(lst))
		{
			list = ft_lstnew(lst->content, lst->content_size);
			list->next = ft_lstfilter_l(lst->next, f);
		}
		else
			return (ft_lstfilter_l(lst->next, f));
		return (list);
	}
}
